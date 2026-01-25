#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_USERS 100
#define MAX_STRING 100

// Định nghĩa struct Book
typedef struct Book {
    int id;
    char title[MAX_STRING];
    char author[MAX_STRING];
    int year;
    char status[20]; // "Available", "Borrowed"
    struct Book* next;
} Book;

// Định nghĩa struct User
typedef struct {
    int id;
    char name[MAX_STRING];
    char borrowed_books[10][MAX_STRING]; // Tối đa 10 sách
    int num_borrowed;
} User;

// Khai báo các hàm
Book* createBook(int id, char* title, char* author, int year);
void addBook(Book** head);
void displayBooks(Book* head);
void searchByTitle(Book* head);
void searchByAuthor(Book* head);
void borrowBook(Book* head, User users[], int user_count);
void returnBook(Book* head, User users[], int user_count);
void saveToFile(Book* head, User users[], int user_count);
void loadFromFile(Book** head, User users[], int* user_count);
void addUser(User users[], int* user_count);
void displayUsers(User users[], int user_count);
void sortBooksByYear(Book** head);
void sortBooksByTitle(Book** head);
void displayMenu();
void freeBookList(Book* head);
Book* findBookById(Book* head, int id);
User* findUserById(User users[], int user_count, int id);

int main() {
    Book* book_head = NULL;
    User users[MAX_USERS];
    int user_count = 0;
    int choice;
    
    // Tải dữ liệu từ file
    loadFromFile(&book_head, users, &user_count);
    
    printf("=== HE THONG QUAN LY THU VIEN ===\n");
    
    do {
        displayMenu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addBook(&book_head);
                break;
            case 2:
                displayBooks(book_head);
                break;
            case 3:
                searchByTitle(book_head);
                break;
            case 4:
                searchByAuthor(book_head);
                break;
            case 5:
                addUser(users, &user_count);
                break;
            case 6:
                displayUsers(users, user_count);
                break;
            case 7:
                borrowBook(book_head, users, user_count);
                break;
            case 8:
                returnBook(book_head, users, user_count);
                break;
            case 9:
                sortBooksByYear(&book_head);
                printf("Da sap xep sach theo nam xuat ban!\n");
                break;
            case 10:
                sortBooksByTitle(&book_head);
                printf("Da sap xep sach theo ten!\n");
                break;
            case 11:
                saveToFile(book_head, users, user_count);
                break;
            case 0:
                saveToFile(book_head, users, user_count);
                printf("Cam on ban da su dung he thong!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
        
        if(choice != 0) {
            printf("\nNhan Enter de tiep tuc...");
            getchar();
            getchar();
        }
        
    } while(choice != 0);
    
    freeBookList(book_head);
    return 0;
}
// Hiển thị menu
void displayMenu() {
    printf("\n================= MENU =================\n");
    printf("1.  Them sach moi\n");
    printf("2.  Hien thi danh sach sach\n");
    printf("3.  Tim kiem theo ten sach\n");
    printf("4.  Tim kiem theo tac gia\n");
    printf("5.  Them nguoi dung\n");
    printf("6.  Hien thi danh sach nguoi dung\n");
    printf("7.  Muon sach\n");
    printf("8.  Tra sach\n");
    printf("9.  Sap xep theo nam xuat ban\n");
    printf("10. Sap xep theo ten sach\n");
    printf("11. Luu du lieu\n");
    printf("0.  Thoat\n");
    printf("========================================\n");
}

// Tạo node sách mới
Book* createBook(int id, char* title, char* author, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if(newBook == NULL) {
        printf("Loi cap phat bo nho!\n");
        return NULL;
    }
    
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    strcpy(newBook->status, "Available");
    newBook->next = NULL;
    
    return newBook;
}

// Thêm sách mới
void addBook(Book** head) {
    int id, year;
    char title[MAX_STRING], author[MAX_STRING];
    
    printf("\n=== THEM SACH MOI ===\n");
    printf("Nhap ID sach: ");
    scanf("%d", &id);
    
    // Kiểm tra ID đã tồn tại
    Book* current = *head;
    while(current != NULL) {
        if(current->id == id) {
            printf("ID sach da ton tai!\n");
            return;
        }
        current = current->next;
    }
    
    printf("Nhap ten sach: ");
    getchar();
    fgets(title, MAX_STRING, stdin);
    title[strcspn(title, "\n")] = 0;
    
    printf("Nhap tac gia: ");
    fgets(author, MAX_STRING, stdin);
    author[strcspn(author, "\n")] = 0;
    
    printf("Nhap nam xuat ban: ");
    scanf("%d", &year);
    
    Book* newBook = createBook(id, title, author, year);
    if(newBook == NULL) return;
    
    // Thêm vào đầu danh sách
    newBook->next = *head;
    *head = newBook;
    
    printf("Them sach thanh cong!\n");
}

// Hiển thị danh sách sách
void displayBooks(Book* head) {
    if(head == NULL) {
        printf("Thu vien chua co sach nao!\n");
        return;
    }
    
    printf("\n=== DANH SACH SACH ===\n");
    printf("%-5s %-30s %-20s %-6s %-12s\n", "ID", "Ten sach", "Tac gia", "Nam", "Trang thai");
    printf("------------------------------------------------------------------------\n");
    
    Book* current = head;
    while(current != NULL) {
        printf("%-5d %-30s %-20s %-6d %-12s\n", 
               current->id, current->title, current->author, 
               current->year, current->status);
        current = current->next;
    }
}
// Tìm kiếm theo tên sách
void searchByTitle(Book* head) {
    char searchTitle[MAX_STRING];
    printf("Nhap ten sach can tim: ");
    getchar();
    fgets(searchTitle, MAX_STRING, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;
    
    printf("\n=== KET QUA TIM KIEM ===\n");
    Book* current = head;
    int found = 0;
    
    while(current != NULL) {
        if(strstr(current->title, searchTitle) != NULL) {
            printf("ID: %d, Ten: %s, Tac gia: %s, Nam: %d, Trang thai: %s\n",
                   current->id, current->title, current->author, 
                   current->year, current->status);
            found = 1;
        }
        current = current->next;
    }
    
    if(!found) {
        printf("Khong tim thay sach nao co ten chua '%s'\n", searchTitle);
    }
}

// Tìm kiếm theo tác giả
void searchByAuthor(Book* head) {
    char searchAuthor[MAX_STRING];
    printf("Nhap ten tac gia can tim: ");
    getchar();
    fgets(searchAuthor, MAX_STRING, stdin);
    searchAuthor[strcspn(searchAuthor, "\n")] = 0;
    
    printf("\n=== KET QUA TIM KIEM ===\n");
    Book* current = head;
    int found = 0;
    
    while(current != NULL) {
        if(strstr(current->author, searchAuthor) != NULL) {
            printf("ID: %d, Ten: %s, Tac gia: %s, Nam: %d, Trang thai: %s\n",
                   current->id, current->title, current->author, 
                   current->year, current->status);
            found = 1;
        }
        current = current->next;
    }
    
    if(!found) {
        printf("Khong tim thay sach nao cua tac gia '%s'\n", searchAuthor);
    }
}

// Thêm người dùng
void addUser(User users[], int* user_count) {
    if(*user_count >= MAX_USERS) {
        printf("Danh sach nguoi dung da day!\n");
        return;
    }
    
    printf("\n=== THEM NGUOI DUNG ===\n");
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &users[*user_count].id);
    
    // Kiểm tra ID đã tồn tại
    for(int i = 0; i < *user_count; i++) {
        if(users[i].id == users[*user_count].id) {
            printf("ID nguoi dung da ton tai!\n");
            return;
        }
    }
    
    printf("Nhap ten nguoi dung: ");
    getchar();
    fgets(users[*user_count].name, MAX_STRING, stdin);
    users[*user_count].name[strcspn(users[*user_count].name, "\n")] = 0;
    
    users[*user_count].num_borrowed = 0;
    (*user_count)++;
    
    printf("Them nguoi dung thanh cong!\n");
}

// Hiển thị danh sách người dùng
void displayUsers(User users[], int user_count) {
    if(user_count == 0) {
        printf("Chua co nguoi dung nao!\n");
        return;
    }
    
    printf("\n=== DANH SACH NGUOI DUNG ===\n");
    printf("%-5s %-25s %-15s\n", "ID", "Ten", "So sach muon");
    printf("-----------------------------------------------\n");
    
    for(int i = 0; i < user_count; i++) {
        printf("%-5d %-25s %-15d\n", 
               users[i].id, users[i].name, users[i].num_borrowed);
        
        if(users[i].num_borrowed > 0) {
            printf("      Sach dang muon: ");
            for(int j = 0; j < users[i].num_borrowed; j++) {
                printf("%s", users[i].borrowed_books[j]);
                if(j < users[i].num_borrowed - 1) printf(", ");
            }
            printf("\n");
        }
    }
}
// Mượn sách
void borrowBook(Book* head, User users[], int user_count) {
    int user_id, book_id;
    
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &user_id);
    
    // Tìm người dùng
    int user_index = -1;
    for(int i = 0; i < user_count; i++) {
        if(users[i].id == user_id) {
            user_index = i;
            break;
        }
    }
    
    if(user_index == -1) {
        printf("Khong tim thay nguoi dung!\n");
        return;
    }
    
    if(users[user_index].num_borrowed >= 10) {
        printf("Nguoi dung da muon toi da 10 sach!\n");
        return;
    }
    
    printf("Nhap ID sach can muon: ");
    scanf("%d", &book_id);
    
    // Tìm sách
    Book* current = head;
    while(current != NULL) {
        if(current->id == book_id) {
            if(strcmp(current->status, "Available") == 0) {
                strcpy(current->status, "Borrowed");
                strcpy(users[user_index].borrowed_books[users[user_index].num_borrowed], 
                       current->title);
                users[user_index].num_borrowed++;
                printf("Muon sach thanh cong!\n");
                printf("Nguoi dung %s da muon sach '%s'\n", 
                       users[user_index].name, current->title);
                return;
            } else {
                printf("Sach da duoc muon!\n");
                return;
            }
        }
        current = current->next;
    }
    
    printf("Khong tim thay sach co ID %d\n", book_id);
}

// Trả sách
void returnBook(Book* head, User users[], int user_count) {
    int user_id, book_id;
    
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &user_id);
    
    // Tìm người dùng
    int user_index = -1;
    for(int i = 0; i < user_count; i++) {
        if(users[i].id == user_id) {
            user_index = i;
            break;
        }
    }
    
    if(user_index == -1) {
        printf("Khong tim thay nguoi dung!\n");
        return;
    }
    
    printf("Nhap ID sach can tra: ");
    scanf("%d", &book_id);
    
    // Tìm sách
    Book* current = head;
    while(current != NULL) {
        if(current->id == book_id) {
            if(strcmp(current->status, "Borrowed") == 0) {
                strcpy(current->status, "Available");
                
                // Xóa sách khỏi danh sách mượn của người dùng
                for(int i = 0; i < users[user_index].num_borrowed; i++) {
                    if(strcmp(users[user_index].borrowed_books[i], current->title) == 0) {
                        // Dịch chuyển các phần tử
                        for(int j = i; j < users[user_index].num_borrowed - 1; j++) {
                            strcpy(users[user_index].borrowed_books[j], 
                                   users[user_index].borrowed_books[j + 1]);
                        }
                        users[user_index].num_borrowed--;
                        break;
                    }
                }
                
                printf("Tra sach thanh cong!\n");
                printf("Nguoi dung %s da tra sach '%s'\n", 
                       users[user_index].name, current->title);
                return;
            } else {
                printf("Sach chua duoc muon!\n");
                return;
            }
        }
        current = current->next;
    }
    
    printf("Khong tim thay sach co ID %d\n", book_id);
}
// Sắp xếp sách theo năm xuất bản (sử dụng bubble sort)
void sortBooksByYear(Book** head) {
    if(*head == NULL || (*head)->next == NULL) return;
    
    int swapped;
    Book* ptr1;
    Book* lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = *head;
        
        while(ptr1->next != lptr) {
            if(ptr1->year > ptr1->next->year) {
                // Hoán đổi dữ liệu
                int temp_id = ptr1->id;
                char temp_title[MAX_STRING], temp_author[MAX_STRING], temp_status[20];
                int temp_year = ptr1->year;
                
                ptr1->id = ptr1->next->id;
                strcpy(temp_title, ptr1->title);
                strcpy(ptr1->title, ptr1->next->title);
                strcpy(ptr1->next->title, temp_title);
                
                strcpy(temp_author, ptr1->author);
                strcpy(ptr1->author, ptr1->next->author);
                strcpy(ptr1->next->author, temp_author);
                
                strcpy(temp_status, ptr1->status);
                strcpy(ptr1->status, ptr1->next->status);
                strcpy(ptr1->next->status, temp_status);
                
                ptr1->year = ptr1->next->year;
                ptr1->next->id = temp_id;
                ptr1->next->year = temp_year;
                
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

// Sắp xếp sách theo tên (sử dụng bubble sort)
void sortBooksByTitle(Book** head) {
    if(*head == NULL || (*head)->next == NULL) return;
    
    int swapped;
    Book* ptr1;
    Book* lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = *head;
        
        while(ptr1->next != lptr) {
            if(strcmp(ptr1->title, ptr1->next->title) > 0) {
                // Hoán đổi dữ liệu
                int temp_id = ptr1->id;
                char temp_title[MAX_STRING], temp_author[MAX_STRING], temp_status[20];
                int temp_year = ptr1->year;
                
                ptr1->id = ptr1->next->id;
                strcpy(temp_title, ptr1->title);
                strcpy(ptr1->title, ptr1->next->title);
                strcpy(ptr1->next->title, temp_title);
                
                strcpy(temp_author, ptr1->author);
                strcpy(ptr1->author, ptr1->next->author);
                strcpy(ptr1->next->author, temp_author);
                
                strcpy(temp_status, ptr1->status);
                strcpy(ptr1->status, ptr1->next->status);
                strcpy(ptr1->next->status, temp_status);
                
                ptr1->year = ptr1->next->year;
                ptr1->next->id = temp_id;
                ptr1->next->year = temp_year;
                
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}
// Lưu dữ liệu vào file
void saveToFile(Book* head, User users[], int user_count) {
    // Lưu dữ liệu sách
    FILE* book_file = fopen("books.txt", "w");
    if(book_file == NULL) {
        printf("Khong the mo file books.txt de ghi!\n");
        return;
    }
    
    Book* current = head;
    while(current != NULL) {
        fprintf(book_file, "%d|%s|%s|%d|%s\n", 
                current->id, current->title, current->author, 
                current->year, current->status);
        current = current->next;
    }
    fclose(book_file);
    
    // Lưu dữ liệu người dùng
    FILE* user_file = fopen("users.txt", "w");
    if(user_file == NULL) {
        printf("Khong the mo file users.txt de ghi!\n");
        return;
    }
    
    fprintf(user_file, "%d\n", user_count);
    for(int i = 0; i < user_count; i++) {
        fprintf(user_file, "%d|%s|%d", 
                users[i].id, users[i].name, users[i].num_borrowed);
        
        for(int j = 0; j < users[i].num_borrowed; j++) {
            fprintf(user_file, "|%s", users[i].borrowed_books[j]);
        }
        fprintf(user_file, "\n");
    }
    fclose(user_file);
    
    printf("Da luu du lieu vao file!\n");
}

// Đọc dữ liệu từ file
void loadFromFile(Book** head, User users[], int* user_count) {
    // Đọc dữ liệu sách
    FILE* book_file = fopen("books.txt", "r");
    if(book_file != NULL) {
        char line[500];
        while(fgets(line, sizeof(line), book_file)) {
            int id, year;
            char title[MAX_STRING], author[MAX_STRING], status[20];
            
            char* token = strtok(line, "|");
            if(token) id = atoi(token);
            
            token = strtok(NULL, "|");
            if(token) strcpy(title, token);
            
            token = strtok(NULL, "|");
            if(token) strcpy(author, token);
            
            token = strtok(NULL, "|");
            if(token) year = atoi(token);
            
            token = strtok(NULL, "|\n");
            if(token) strcpy(status, token);
            
            Book* newBook = createBook(id, title, author, year);
            if(newBook) {
                strcpy(newBook->status, status);
                newBook->next = *head;
                *head = newBook;
            }
        }
        fclose(book_file);
        printf("Da tai du lieu sach tu file!\n");
    }
    
    // Đọc dữ liệu người dùng
    FILE* user_file = fopen("users.txt", "r");
    if(user_file != NULL) {
        fscanf(user_file, "%d\n", user_count);
        
        for(int i = 0; i < *user_count; i++) {
            char line[500];
            if(fgets(line, sizeof(line), user_file)) {
                char* token = strtok(line, "|");
                if(token) users[i].id = atoi(token);
                
                token = strtok(NULL, "|");
                if(token) strcpy(users[i].name, token);
                
                token = strtok(NULL, "|");
                if(token) users[i].num_borrowed = atoi(token);
                
                for(int j = 0; j < users[i].num_borrowed; j++) {
                    token = strtok(NULL, "|\n");
                    if(token) strcpy(users[i].borrowed_books[j], token);
                }
            }
        }
        fclose(user_file);
        printf("Da tai du lieu nguoi dung tu file!\n");
    } else {
        *user_count = 0;
    }
}

// Giải phóng bộ nhớ
void freeBookList(Book* head) {
    Book* current = head;
    while(current != NULL) {
        Book* next = current->next;
        free(current);
        current = next;
    }
}

// Tìm sách theo ID (sử dụng break)
Book* findBookById(Book* head, int id) {
    Book* current = head;
    while(current != NULL) {
        if(current->id == id) {
            break; // Thoát vòng lặp khi tìm thấy
        }
        current = current->next;
    }
    return current; // Trả về NULL nếu không tìm thấy
}

// Tìm người dùng theo ID (sử dụng break)
User* findUserById(User users[], int user_count, int id) {
    for(int i = 0; i < user_count; i++) {
        if(users[i].id == id) {
            return &users[i]; // Tìm thấy, thoát ngay
        }
    }
    return NULL; // Không tìm thấy
}
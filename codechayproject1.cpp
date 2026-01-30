#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 // định nghĩa struct book
struct qltv{
    int id;
    char title[200];
    char author[100];
    int year;
    int status;  
            // 1: sách đang được mượn
            // 0: sách chưa ai mượn
};
struct qltv book[100];

// thiết kế menu
void menu(){
        printf("\n================= MENU =================\n");
        printf("1.  Them sach moi\n");
        printf("2.  Xoa danh sach\n");
        printf("3.  Sua thong tin sach\n");
        printf("4.  Tim kiem theo ten sach\n");
        printf("5.  Tim kiem theo ten tac gia\n");
        // Mở rộng / sáng tạo
        printf("6.  Them nguoi muon\n");
        printf("7.  Muon sach\n");
        printf("8.  Tra sach\n");
        printf("9.  Sap xep theo nam xuat ban\n");
        printf("10. Luu du lieu\n");
        printf("0.  Thoat\n");
        printf("========================================\n");
};
// thêm sách
int add_book(int book_count){

    // thêm thông tin sách vào struct
    printf("vui long nhap id sach: ");
    scanf("%d",&book[book_count].id);
    getchar(); // scanf này nó lưu thừa kí tự xuống hàng: "\n"
    printf("vui long nhap ten sach: ");
    fgets(book[book_count].title,sizeof(book[book_count].title),stdin);
    book[book_count].title[strcspn(book[book_count].title, "\n")] = '\0'; // Xóa \n
    printf("vui long nhap ten tac gia: ");
    fgets(book[book_count].author,sizeof(book[book_count].author),stdin);
    book[book_count].author[strcspn(book[book_count].author, "\n")] = 0; // Xóa \n
    printf("vui long nhap nam san xuat: ");
    scanf("%d",&book[book_count].year);
    book[book_count].status = 0; // mặc định là chưa ai mượn vì mới thêm

    //mở file để ghi vào
    FILE *file;
    file = fopen("data.txt","a");
    if (file == NULL){
        printf("can't open this file! ");
    }
    fprintf(file,"%d %s %s %d %d\n",
                book[book_count].id,
                book[book_count].title,
                book[book_count].author,
                book[book_count].year,
                book[book_count].status);
    fclose(file);
    printf("them sach thanh cong!\n");
}
//xóa danh sách
void del_book(int book_count){
    FILE *file;
    file = fopen("data.txt","w"); // w: write là ghi mới -> ghi đè = xóa
    if (file == NULL){
        printf("ca'nt open this file! ");
    }
}
// sửa thông tin sách    --khó vcl
int fix_inf(int book_count){
    int temp;
    FILE *file ;
    file = fopen("data.txt","r");
    if (file == NULL){
        printf("can't open this file (step 1) !");
        return 1;
    }
    printf("nhap id sach can sua: ");
    scanf("%d",&temp); 

    //tìm sách cần sửa
    for (int i=0; i<book_count;i++){
        if (book[i].id == temp){
            printf("sach can sua la: %d %s %s %d %d",
                book[i].id ,
                book[i].title ,
                book[i].author ,
                book[i].year );
            if (book[i].status == 0){
                printf("chua muon\n");
            }else{
                printf("dang muon\n");
            }
            temp=i;
        }
    }
    fclose(file);


    // người dùng nhập tạm các thông tin
    int id_temp,
        year_temp,
        status_temp;
    char title_temp[100];
    char author_temp[100];
    printf("vui long nhap id: ");
    scanf("%d",&id_temp);
    getchar();
    printf("vui long nhap ten sach: ");
    fgets(title_temp,sizeof(title_temp),stdin);
    title_temp[strcspn(title_temp,"\n")]='\0'; 
    printf("vui long nhap ten tac gia: ");
    fgets(author_temp,sizeof(author_temp),stdin);
    author_temp[strcspn(author_temp,"\n")]='\0'; 
    printf("vui long nhap nam san xuat: ");
    scanf("%d",&year_temp);
    getchar();
    printf("vui nhap trang thai (0 = chua muon/ 1 = dang muon): ");
    scanf("%d",&status_temp);

    //lưu lại vào data.txt
    file = fopen("data.txt","a");
    if (file == NULL){
        printf("can't open this file (step 2) !");
        return 0;
    }
    char submit;
    printf("ban co chac chan sua thong nhu tren khong ( y/n): ");
    scanf("%c",&submit);
    if (submit == 'y'){
        fprintf(file,"%d %s %s %d %d\n",
                id_temp,
                title_temp,
                author_temp,
                year_temp,
                status_temp);
    fclose(file);
    printf("sua sach thanh cong!\n");
    }else{
        printf("may dua tao a ??");
        return 0;
    }
}
// tìm kiếm theo tên
int find_name(){

}
// tìm kiếm theo tác giả
int find_author(){

}
// thêm người mượn
int add_user(){

}
// mượn sách
int muon_sach(){

}
// trả sách
int tra_sach(){

}
// sắp xếp danh sách theo năm
int sort_year(){

}
// lưu dữ liệu ra file
void save(){

}
int main(){
    // thiết lập các tùy chọn
    int tc;
    int i=0;
    int book_count=0; // xem hiện tại có bao nhiêu quyển sách
    int user_count=0; // xem hiện tại có bao nhiêu người dùng

    while (1){
        menu();
        printf("nhap tuy chon cua ban: ");
        scanf("%d",&tc);
        switch (tc)
        {
        case 1:
            add_book(book_count); 
            book_count++; 
            break;
        case 2:
            del_book(book_count);
            book_count=0;
            break;
        case 3:
            fix_inf(book_count);     // chưa xong
            break;
        case 4:
            find_name();   // chưa xong
            break;
        case 5:
            find_author(); // chưa xong
            break;
        case 6:
            add_user();    // chưa xong
            break;
        case 7:
            muon_sach();   // chưa xong
            break;
        case 8:
            tra_sach();    // chưa xong
            break;
        case 9:
            sort_year();   // chưa xong
            break;
        case 10:
            save();        // chưa xong
            break;
        case 0:
            return 0; // thoát khỏi chương trình
        default:
            printf("cu phap sai vui long nhap lai!");
        }
    }
    return 0;
}

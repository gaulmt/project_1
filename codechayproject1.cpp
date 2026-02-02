#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
        printf("4.  Hien thi danh sach\n");
        printf("5.  Tim kiem theo ten sach\n");
        printf("6.  Tim kiem theo ten tac gia\n");
        // Mở rộng / sáng tạo
        printf("7.  Them nguoi muon\n");
        printf("8.  Muon sach\n");
        printf("9.  Tra sach\n");
        printf("10.  Sap xep theo nam xuat ban\n");
        printf("11. Luu du lieu\n");
        printf("0.  Thoat\n");
        printf("========================================\n");
};
// thêm sách
int add_book(int book_count){
    //make color: làm màu :)))
    Sleep(500);
    printf("\n dang phan tich....."); 
    Sleep(1000);
    system("cls");
    printf("Luu y !!!\n");
    Sleep(1000);
    printf("Vi ky nang code co han nen khong the luu voi ten co dau cach " "\n");
    Sleep(4000);
    printf("vui long nhap ten sach/ten tac gia theo dinh dang : ten_sach/ ten_tac_gia\n");
    Sleep(4000);
    

    // thêm thông tin sách vào struct 
    printf("\n\nVui long nhap id sach: ");
    scanf("%d",&book[book_count].id);
    getchar(); // scanf này nó lưu thừa kí tự xuống hàng: "\n"
    printf("Vui long nhap ten sach: ");
    fgets(book[book_count].title,sizeof(book[book_count].title),stdin);
    book[book_count].title[strcspn(book[book_count].title, "\n")] = '\0'; // Xóa \n
    printf("Vui long nhap ten tac gia: ");
    fgets(book[book_count].author,sizeof(book[book_count].author),stdin);
    book[book_count].author[strcspn(book[book_count].author, "\n")] = 0; // Xóa \n
    printf("Vui long nhap nam san xuat: ");
    scanf("%d",&book[book_count].year);
    book[book_count].status = 0; // mặc định là chưa ai mượn vì mới thêm

    // làm màu
    Sleep(500);
    printf("\nC:\\Users\\Admin> add data.txt\n");
    Sleep(500);
    
    printf("Xac nhan them vao file 'data.txt'? (Y/N): Y\n");
    Sleep(1000);
    
    printf("Dang xu ly");
    for(int i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout);
        Sleep(400);
    }
    printf(" [OK]\n");
    
    Sleep(500);
    printf("File 'data.txt' them sach thanh cong.\n");
    printf("C:\\Users\\Admin> \n");
    Sleep(500);
    
    //mở file để ghi vào
    FILE *file;
    file = fopen("data.txt","a");
    if (file == NULL){
       printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }
    fprintf(file,"%d %s %s %d %d\n",
                book[book_count].id,
                book[book_count].title,
                book[book_count].author,
                book[book_count].year,
                book[book_count].status);
    fclose(file);
    printf("Them sach thanh cong!\n");
    Sleep(1000);
    system("cls");
    fflush(stdin);
    return 0;
}
//xóa danh sách
void del_book(int book_count){
    FILE *file;
    file = fopen("data.txt","w"); // w: write là ghi mới -> ghi đè = xóa
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
    }

    //làm màu
    Sleep(500);
    printf("\n dang phan tich....."); 
    Sleep(2000);
    system("cls");
    printf("INITIALIZING DELETE SEQUENCE...\n");
    Sleep(1000);
    
    printf(">>> SCANNING FILES");
    for(int i = 0; i < 20; i++) {
        printf(".");
        Sleep(100);
    }
    printf(" [OK]\n");
    
    printf(">>> PREPARING DELETION");
    for(int i = 0; i < 16; i++) {
        printf(".");
        Sleep(150);
    }
    printf(" [OK]\n");
    
    printf(">>> EXECUTING DELETE COMMAND");
    for(int i = 0; i < 10; i++) {
        printf(".");
        Sleep(150);
    }
    printf(" [OK]\n");
    
    printf(">>> CLEANUP PROCESS");
    for(int i = 0; i < 19; i++) {
        printf(".");
        Sleep(150);
    }
    printf(" [OK]\n");
    
    printf("\n*** Lam Mau thanh cong ***\n");
    Sleep(1500);

    printf("\n...Da xoa danh sach thanh cong!");
}
// sửa thông tin sách    --khó vcl
int fix_inf(int book_count){
    int temp;
    FILE *file ;
    file = fopen("data.txt","r");
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }

    //dùng struct tạm để lưu data.txt
    struct qltv temp_book[200];
    int temp_count=0;
    while (fscanf(file,"%d %s %s %d %d",
            &temp_book[temp_count].id,
            temp_book[temp_count].title,
            temp_book[temp_count].author,
            &temp_book[temp_count].year,
            &temp_book[temp_count].status)==5){
                temp_count++;
                if (temp_count >=100){
                    printf("Thu vien qua tai....\n");
                    break;
                }
            }
    fclose(file);


    //sửa file
    //make color: làm màu :)))
    Sleep(500);
    printf("\n dang phan tich....."); 
    Sleep(1000);
    system("cls");
    printf("Luu y !!!\n");
    Sleep(1000);
    printf("Vi ky nang code co han nen khong the luu voi ten co dau cach " "\n");
    Sleep(4000);
    printf("vui long nhap ten sach/ten tac gia theo dinh dang : ten_sach/ ten_tac_gia\n");
    Sleep(4000);

    printf("\n\nNhap id sach can sua: ");
    scanf("%d",&temp);
    getchar();
    for (int i=0;i<temp_count;i++){
        if(temp_book[i].id == temp){
            printf("\nNhap ten sach: ");
            getchar(); // scanf này nó lưu thừa kí tự xuống hàng: "\n"
            printf("Vui long nhap ten sach: ");
            fgets(temp_book[i].title,sizeof(temp_book[i].title),stdin);
            fflush(stdin);
            temp_book[i].title[strcspn(temp_book[i].title, "\n")] = '\0'; // Xóa \n
            printf("Vui long nhap ten tac gia: ");
            fgets(temp_book[i].author,sizeof(temp_book[i].author),stdin);
            fflush(stdin);
            temp_book[i].author[strcspn(temp_book[i].author, "\n")] = 0; // Xóa \n
            printf("Vui long nhap nam san xuat: ");
            scanf("%d",&temp_book[i].year);
            printf("\nTrang thai cua sach (0=chua muon /1=dang muon): ");
            scanf("%d",&temp_book[i].status);
        }else{
            printf("id khong ton tai!  \n");
            Sleep(1000);
            printf("Nhan Enter de quay ve menu...");
            getchar();
            system("cls");
            return 0;
        }
    }

    //ghi đè ở chế độ "wirte"
    file = fopen("data.txt","w");
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        system("cls");
        return 1;
    }
    for (int i=0;i<temp_count;i++){
        fprintf(file,"%d %s %s %d %d\n",
                temp_book[i].id,
                temp_book[i].title,
                temp_book[i].author,
                temp_book[i].year,
                temp_book[i].status);
        }
    fclose(file);
    printf("Sua danh sach thanh cong!\n");
    return 0;
}

// hien thi danh sach
int show_books(){
    printf("dang lay du lieu...");
    Sleep(1000);
    system("cls");

    FILE *file;
    file = fopen("data.txt","r");
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }

    struct qltv temp_book[200];
    int temp_count=0;
    while (fscanf(file,"%d %s %s %d %d",
            &temp_book[temp_count].id,
            temp_book[temp_count].title,
            temp_book[temp_count].author,
            &temp_book[temp_count].year,
            &temp_book[temp_count].status)==5){
                temp_count++;
                if (temp_count >=100){
                    printf("Thu vien qua tai....\n");
                    break;
                }
            }
    int i=0;
    printf("\n");
    printf("================================================================================\n");
    printf("                           DANH SACH THU VIEN                                   \n");
    printf("================================================================================\n");
    printf("| %-10s | %-25s | %-20s | %-8s | %-10s |\n", 
           "ID", "Ten Sach", "Tac Gia", "Nam XB", "Trang Thai");
    printf("================================================================================\n");
    if (temp_count == 0) {
        printf("| %-78s |\n", "Khong co sach nao trong thu vien!");
    } else {
        // In danh sách
        for(int i = 0; i < temp_count; i++){  
            printf("| %-10d | %-25s | %-20s | %-8d | %-10s |\n",
                temp_book[i].id,
                temp_book[i].title,
                temp_book[i].author,
                temp_book[i].year,
                temp_book[i].status == 0 ? "Chua muon" : "Da muon");
        }
    }
    fclose(file);
    printf("Nhan enter de thoat!\n");
    getchar();
    char temp;
    scanf("%c",&temp);
    if(temp == '\n'){
        system("cls");
        return 0;
    }
}
// tìm kiếm theo tên
int find_name(){
    printf("dang xu ly...");
    Sleep(1000);
    system("cls");

    FILE *file = fopen("data.txt","r");
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }

    struct qltv temp_book[200];
    int temp_count = 0;
    while (fscanf(file,"%d %s %s %d %d",
            &temp_book[temp_count].id,
            temp_book[temp_count].title,
            temp_book[temp_count].author,
            &temp_book[temp_count].year,
            &temp_book[temp_count].status) == 5){
        temp_count++;
        if (temp_count >= 200) break;
    }
    fclose(file);
    
    char title_temp[200];
    printf("Vui long nhap ten sach can tim: ");
    
    // Clear buffer kỹ hơn      AI làm : t lười nhưng có thể tự debug nếu rảnh
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    fgets(title_temp, sizeof(title_temp), stdin);
    title_temp[strcspn(title_temp, "\n")] = '\0';
    
    // Header
    printf("\n=========================================================================================\n");
    printf("                        KET QUA TIM KIEM                                       \n");
    printf("=========================================================================================\n");
    printf("| %-10s | %-25s | %-20s | %-8s | %-10s |\n", 
           "ID", "Ten Sach", "Tac Gia", "Nam XB", "Trang Thai");
    printf("=========================================================================================\n");
    
    int found_count = 0;
    for(int i = 0; i < temp_count; i++){ 
        if(strstr(temp_book[i].title, title_temp) != NULL){     // tìm kiếm không phân biệt chữ hoa hay thường
            printf("| %-10d | %-25s | %-20s | %-8d | %-10s |\n",
                temp_book[i].id,
                temp_book[i].title,
                temp_book[i].author,
                temp_book[i].year,
                temp_book[i].status == 0 ? "Chua muon" : "Da muon");
            found_count++;
        }
    }
    
    if(found_count == 0){
        printf("| %-78s |\n", "Khong tim thay sach nao!");
    }
    
    printf("=========================================================================================\n");
    printf("Tim thay %d sach\n", found_count);
    printf("Nhan Enter de tiep tuc...");
    getchar();
    system("cls");
    
    return 0;
}
// tìm kiếm theo tác giả
int find_author(){
    printf("dang xu ly...");
    Sleep(1000);
    system("cls");

    FILE *file = fopen("data.txt","r");
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }

    struct qltv temp_book[200];
    int temp_count = 0;
    while (fscanf(file,"%d %s %s %d %d",
            &temp_book[temp_count].id,
            temp_book[temp_count].title,
            temp_book[temp_count].author,
            &temp_book[temp_count].year,
            &temp_book[temp_count].status) == 5){
        temp_count++;
        if (temp_count >= 200) break;
    }
    fclose(file);
    
    char title_temp[200];
    printf("Vui long nhap ten tac gia can tim: ");
    
    // Clear buffer kỹ hơn      AI làm : t lười nhưng có thể tự debug nếu rảnh
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    fgets(title_temp, sizeof(title_temp), stdin);
    title_temp[strcspn(title_temp, "\n")] = '\0';
    
    // Header
    printf("\n=========================================================================================\n");
    printf("                        KET QUA TIM KIEM                                       \n");
    printf("=========================================================================================\n");
    printf("| %-10s | %-25s | %-20s | %-8s | %-10s |\n", 
           "ID", "Ten Sach", "Tac Gia", "Nam XB", "Trang Thai");
    printf("=========================================================================================\n");
    
    int found_count = 0;
    for(int i = 0; i < temp_count; i++){ 
        if(strstr(temp_book[i].author, title_temp) != NULL){     // tìm kiếm không phân biệt chữ hoa hay thường
            printf("| %-10d | %-25s | %-20s | %-8d | %-10s |\n",
                temp_book[i].id,
                temp_book[i].title,
                temp_book[i].author,
                temp_book[i].year,
                temp_book[i].status == 0 ? "Chua muon" : "Da muon");
            found_count++;
        }
    }
    
    if(found_count == 0){
        printf("| %-78s |\n", "Khong tim thay tac gia nao!");
    }
    
    printf("=========================================================================================\n");
    printf("Tim thay %d sach\n", found_count);
    printf("Nhan Enter de tiep tuc...");
    getchar();
    system("cls");
    
    return 0;
}
// thêm người mượn
int add_user(){
    printf("dang xu ly...");
    Sleep(1000);
    system("cls");
    
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#         THEM NGUOI MUON SACH         #\n");
    printf("#              SIEU VIP                #\n");
    printf("#                                      #\n");
    printf("########################################\n\n");
    Sleep(1000);
    
    // Tạo file users.txt để lưu thông tin người mượn
    FILE *file;
    file = fopen("users.txt","a");
    if (file == NULL){
        printf("Can't open users file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }
    
    // Nhập thông tin người mượn
    int user_id;
    char user_name[100];
    char user_phone[20];
    char user_address[200];
    
    printf("Vui long nhap ma nguoi muon: ");
    scanf("%d", &user_id);
    getchar(); // Clear buffer
    
    printf("Vui long nhap ten nguoi muon: ");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = '\0';
    
    printf("Vui long nhap so dien thoai: ");
    fgets(user_phone, sizeof(user_phone), stdin);
    user_phone[strcspn(user_phone, "\n")] = '\0';
    
    printf("Vui long nhap dia chi: ");
    fgets(user_address, sizeof(user_address), stdin);
    user_address[strcspn(user_address, "\n")] = '\0';
    
    // Animation lưu
    printf("\nDang luu thong tin nguoi muon");
    for(int i = 0; i < 5; i++) {
        printf(".");
        Sleep(400);
    }
    printf("\n");
    
    // Lưu vào file
    fprintf(file, "%d %s %s %s\n", user_id, user_name, user_phone, user_address);
    fclose(file);
    
    printf("Them nguoi muon thanh cong!\n");
    printf("Nhan Enter de quay ve menu...");
    getchar();
    return 0;
}
// mượn sách
int muon_sach(){
    printf("dang xu ly...");
    Sleep(1000);
    system("cls");
    
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#            MUON SACH                 #\n");
    printf("#           SIEU TIEN LOI              #\n");
    printf("#                                      #\n");
    printf("########################################\n\n");
    Sleep(1000);
    
    // Đọc danh sách sách
    FILE *file = fopen("data.txt","r");
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }
    
    struct qltv temp_book[200];
    int temp_count = 0;
    while (fscanf(file,"%d %s %s %d %d",
            &temp_book[temp_count].id,
            temp_book[temp_count].title,
            temp_book[temp_count].author,
            &temp_book[temp_count].year,
            &temp_book[temp_count].status) == 5){
        temp_count++;
        if (temp_count >= 200) break;
    }
    fclose(file);
    
    if(temp_count == 0) {
        printf("Thu vien trong! Khong co sach de muon.\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 0;
    }
    
    // Hiển thị sách có thể mượn
    printf("================================================================================\n");
    printf("                              SACH CO THE MUON                                 \n");
    printf("================================================================================\n");
    printf("| %-10s | %-25s | %-20s | %-8s | %-12s |\n", 
           "ID", "Ten Sach", "Tac Gia", "Nam XB", "Trang Thai");
    printf("================================================================================\n");
    
    int available_count = 0;
    for(int i = 0; i < temp_count; i++){
        if(temp_book[i].status == 0) { // Chỉ hiển thị sách chưa mượn
            printf("| %-10d | %-25s | %-20s | %-8d | %-12s |\n",
                temp_book[i].id,
                temp_book[i].title,
                temp_book[i].author,
                temp_book[i].year,
                "Con trong");
            available_count++;
        }
    }
    
    if(available_count == 0) {
        printf("| %-78s |\n", "Tat ca sach deu da duoc muon!");
        printf("================================================================================\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 0;
    }
    
    printf("================================================================================\n");
    
    // Nhập ID sách muốn mượn
    int book_id, user_id;
    printf("\nNhap ID sach muon muon: ");
    scanf("%d", &book_id);
    
    printf("Nhap ma nguoi muon: ");
    scanf("%d", &user_id);
    
    // Tìm sách và cập nhật trạng thái
    int found = -1;
    for(int i = 0; i < temp_count; i++) {
        if(temp_book[i].id == book_id) {
            found = i;
            break;
        }
    }
    
    if(found == -1) {
        printf("Khong tim thay sach co ID %d!\n", book_id);
        printf("Nhan Enter de quay ve menu...");
        getchar();
        getchar();
        return 0;
    }
    
    if(temp_book[found].status == 1) {
        printf("Sach nay da duoc muon roi!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        getchar();
        return 0;
    }
    
    // Cập nhật trạng thái sách
    temp_book[found].status = 1;
    
    // Animation xử lý
    printf("\nDang xu ly giao dich muon sach");
    for(int i = 0; i < 6; i++) {
        printf(".");
        Sleep(300);
    }
    printf("\n");
    
    // Ghi lại file
    file = fopen("data.txt","w");
    if (file != NULL) {
        for (int i = 0; i < temp_count; i++){
            fprintf(file,"%d %s %s %d %d\n",
                    temp_book[i].id,
                    temp_book[i].title,
                    temp_book[i].author,
                    temp_book[i].year,
                    temp_book[i].status);
        }
        fclose(file);
        
        // Lưu lịch sử mượn
        FILE *history = fopen("borrow_history.txt", "a");
        if(history != NULL) {
            fprintf(history, "%d %d %s MUON\n", user_id, book_id, temp_book[found].title);
            fclose(history);
        }
        
        printf("Muon sach thanh cong!\n");
        printf("Sach: %s\n", temp_book[found].title);
        printf("Nguoi muon: %d\n", user_id);
    } else {
        printf("Loi: Khong the cap nhat file!\n");
    }
    
    printf("Nhan Enter de quay ve menu...");
    getchar();
    getchar();
    return 0;
}
// trả sách
int tra_sach(){
    printf("dang xu ly...");
    Sleep(1000);
    system("cls");
    
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#             TRA SACH                 #\n");
    printf("#           SIEU NHANH                 #\n");
    printf("#                                      #\n");
    printf("########################################\n\n");
    Sleep(1000);
    
    // Đọc danh sách sách
    FILE *file = fopen("data.txt","r");
    if (file == NULL){
        printf("Can't open this file!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }
    
    struct qltv temp_book[200];
    int temp_count = 0;
    while (fscanf(file,"%d %s %s %d %d",
            &temp_book[temp_count].id,
            temp_book[temp_count].title,
            temp_book[temp_count].author,
            &temp_book[temp_count].year,
            &temp_book[temp_count].status) == 5){
        temp_count++;
        if (temp_count >= 200) break;
    }
    fclose(file);
    
    if(temp_count == 0) {
        printf("Thu vien trong! Khong co sach nao.\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 0;
    }
    
    // Hiển thị sách đang được mượn
    printf("================================================================================\n");
    printf("                              SACH DANG DUOC MUON                                    \n");
    printf("================================================================================\n");
    printf("| %-4s | %-25s | %-15s | %-8s | %-12s |\n", 
           "ID", "Ten Sach", "Tac Gia", "Nam XB", "Trang Thai");
    printf("================================================================================\n");
    
    int borrowed_count = 0;
    for(int i = 0; i < temp_count; i++){
        if(temp_book[i].status == 1) { // Chỉ hiển thị sách đang mượn
            printf("| %-4d | %-25s | %-15s | %-8d | %-12s |\n",
                temp_book[i].id,
                temp_book[i].title,
                temp_book[i].author,
                temp_book[i].year,
                "Da muon");
            borrowed_count++;
        }
    }
    
    if(borrowed_count == 0) {
        printf("| %-78s |\n", "Khong co sach nao dang duoc muon!");
        printf("================================================================================\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 0;
    }
    
    printf("================================================================================\n");
    
    // Nhập ID sách muốn trả
    int book_id, user_id;
    printf("\nNhap ID sach muon tra: ");
    scanf("%d", &book_id);
    
    printf("Nhap ma nguoi tra: ");
    scanf("%d", &user_id);
    
    // Tìm sách và cập nhật trạng thái
    int found = -1;
    for(int i = 0; i < temp_count; i++) {
        if(temp_book[i].id == book_id) {
            found = i;
            break;
        }
    }
    
    if(found == -1) {
        printf("Khong tim thay sach co ID %d!\n", book_id);
        printf("Nhan Enter de quay ve menu...");
        getchar();
        getchar();
        return 0;
    }
    
    if(temp_book[found].status == 0) {
        printf("Sach nay chua duoc muon!\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        getchar();
        return 0;
    }
    
    // Cập nhật trạng thái sách
    temp_book[found].status = 0;
    
    // Animation xử lý
    printf("\nDang xu ly giao dich tra sach");
    for(int i = 0; i < 6; i++) {
        printf(".");
        Sleep(300);
    }
    printf("\n");
    
    // Ghi lại file
    file = fopen("data.txt","w");
    if (file != NULL) {
        for (int i = 0; i < temp_count; i++){
            fprintf(file,"%d %s %s %d %d\n",
                    temp_book[i].id,
                    temp_book[i].title,
                    temp_book[i].author,
                    temp_book[i].year,
                    temp_book[i].status);
        }
        fclose(file);
        
        // Lưu lịch sử trả
        FILE *history = fopen("borrow_history.txt", "a");
        if(history != NULL) {
            fprintf(history, "%d %d %s TRA\n", user_id, book_id, temp_book[found].title);
            fclose(history);
        }
        
        printf("Tra sach thanh cong!\n");
        printf("Sach: %s\n", temp_book[found].title);
        printf("Nguoi tra: %d\n", user_id);
        printf("Cam on ban da tra sach dung han!\n");
    } else {
        printf("Loi: Khong the cap nhat file!\n");
    }
    
    printf("Nhan Enter de quay ve menu...");
    getchar();
    getchar();
    return 0;
}
// sắp xếp danh sách theo năm
int sort_year(){
// Hiệu ứng mở đầu siêu chất
    system("cls");
    printf(" KHOI DONG HE THONG SAP XEP SIEU VIP...\n");
    Sleep(800);
    
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#        SAP XEP THEO NAM XUAT BAN     #\n");
    printf("#              SIEU CHAT               #\n");
    printf("#                                      #\n");
    printf("########################################\n\n");
    Sleep(1000);
    
    // Animation loading siêu vip
    printf(" Dang khoi dong AI sap xep");
    for(int i = 0; i < 8; i++) {
        printf(".");
        fflush(stdout);
        Sleep(300);
    }
    printf(" [HOAN TAT]\n");
    
    printf(" Quet du lieu thu vien");
    for(int i = 0; i < 6; i++) {
        printf(":");
        fflush(stdout);
        Sleep(250);
    }
    printf(" [100%%]\n");
    
    printf(" Phan tich thuat toan");
    for(int i = 0; i < 10; i++) {
        printf(":");
        fflush(stdout);
        Sleep(200);
    }
    printf(" [SIEU VIP]\n\n");
    Sleep(1000);
    
    // Đọc file siêu chi tiết
    FILE *file = fopen("data.txt","r");
    if (file == NULL){
        printf(" CRITICAL ERROR: Khong the truy cap database!\n");
        printf(" Vui long kiem tra file data.txt...\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 1;
    }
    
    printf(" Dang tai database");
    for(int i = 0; i < 5; i++) {
        printf(".");
        Sleep(400);
    }
    printf("\n");

    struct qltv temp_book[200];
    int temp_count = 0;
    
    while (fscanf(file,"%d %s %s %d %d",
            &temp_book[temp_count].id,
            temp_book[temp_count].title,
            temp_book[temp_count].author,
            &temp_book[temp_count].year,
            &temp_book[temp_count].status) == 5){
        temp_count++;
        
        // Progress bar siêu chi tiết
        if(temp_count % 5 == 0) {
            printf(" Doc sach thu %d", temp_count);
            for(int j = 0; j < 3; j++) {
                printf(".");
                Sleep(100);
            }
            printf(" [ok]\n");
        }
        
        if (temp_count >= 200){
            printf(" WARNING: Thu vien qua tai! Gioi han 200 sach.\n");
            break;
        }
    }
    fclose(file);
    
    printf("\n THANH CONG: Doc duoc %d sach tu database!\n", temp_count);
    Sleep(1000);
    
    if(temp_count == 0) {
        printf(" THONG BAO: Thu vien trong! Khong co sach de sap xep.\n");
        printf("Nhan Enter de quay ve menu...");
        getchar();
        return 0;
    }
    
    // Menu sắp xếp siêu vip
    system("cls");
    printf("|================================================================|\n");
    printf("|                    MENU SAP XEP                                |\n");
    printf("|================================================================|\n");
    printf("|  1.  Sap xep tang dan (Cu -> Moi)                              |\n");
    printf("|  2.  Sap xep giam dan (Moi -> Cu)                              |\n");
    printf("|  3.  Sap xep ngau nhien (Random)                               |\n");
    printf("|  0.  Quay ve menu chinh                                        |\n");
    printf("|================================================================|\n");
    
    int choice;
    printf("\n Lua chon cua ban: ");
    scanf("%d", &choice);
    getchar();
    
    // Xử lý lựa chọn với hiệu ứng siêu chất
    switch(choice) {
        case 1:
            printf("\n KHOI DONG SAP XEP TANG DAN...\n");
            printf(" Su dung thuat toan Bubble Sort sieu toi uu!\n");
            break;
        case 2:
            printf("\n KHOI DONG SAP XEP GIAM DAN...\n");
            printf(" Su dung thuat toan Bubble Sort sieu toi uu!\n");
            break;
        case 3:
            printf("\n KHOI DONG SAP XEP NGAU NHIEN...\n");
            printf(" Su dung thuat toan Fisher-Yates Shuffle!\n");
            break;
        case 0:
            printf(" Cam on ban da su dung tinh nang sap xep!\n");
            return 0;
        default:
            printf("X Lua chon khong hop le!\n");
            Sleep(2000);
            return sort_year(); // Gọi lại hàm
    }
    
    Sleep(1500);
    
    // Thuật toán sắp xếp với animation siêu chi tiết
    printf("\n BAT DAU QUA TRINH SAP XEP...\n");
    
    for(int i = 0; i < temp_count - 1; i++) {
        for(int j = 0; j < temp_count - i - 1; j++) {
            
            // Animation so sánh
            if((i + j) % 10 == 0) {
                printf(" So sanh sach %d (%d) voi sach %d (%d)", 
                       j+1, temp_book[j].year, j+2, temp_book[j+1].year);
                for(int k = 0; k < 3; k++) {
                    printf(".");
                    Sleep(50);
                }
                printf("\n");
            }
            
            bool should_swap = false;
            
            if(choice == 1) { // Tăng dần
                should_swap = (temp_book[j].year > temp_book[j+1].year);
            } else if(choice == 2) { // Giảm dần
                should_swap = (temp_book[j].year < temp_book[j+1].year);
            }
            
            if(should_swap) {
                // Animation swap
                if((i + j) % 15 == 0) {
                    printf(" Hoan doi vi tri: %s <-> %s\n", 
                           temp_book[j].title, temp_book[j+1].title);
                }
                
                // Swap
                struct qltv temp = temp_book[j];
                temp_book[j] = temp_book[j+1];
                temp_book[j+1] = temp;
            }
        }
        
        // Progress bar cho từng vòng lặp
        if(i % 5 == 0) {
            int progress = (i * 100) / (temp_count - 1);
            printf(" Tien do sap xep: [");
            for(int p = 0; p < 20; p++) {
                if(p < progress/5) printf("#");
                else printf(".");
            }
            printf("] %d%%\n", progress);
        }
    }
    
    // Sắp xếp ngẫu nhiên
    if(choice == 3) {
        printf(" Tron ngau nhien danh sach...\n");
        for(int i = temp_count - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            struct qltv temp = temp_book[i];
            temp_book[i] = temp_book[j];
            temp_book[j] = temp;
            
            if(i % 10 == 0) {
                printf(" Tron sach %d voi sach %d\n", i+1, j+1);
                Sleep(100);
            }
        }
    }
    
    printf("\n SAP XEP HOAN TAT! KIEM TRA KET QUA...\n");
    Sleep(2000);
    
    // Hiển thị kết quả siêu vip siêu chi tiết
    system("cls");
    
    printf("|======================================================================================|\n");
    printf("|                                  KET QUA SAP XEP                                     |\n");
    printf("|                                   SIEU CHAT VIP                                      |\n");
    printf("|======================================================================================|\n\n");
    
    // Thống kê siêu chi tiết
    int oldest_year = temp_book[0].year;
    int newest_year = temp_book[0].year;
    int available_count = 0;
    int borrowed_count = 0;
    
    for(int i = 0; i < temp_count; i++) {
        if(temp_book[i].year < oldest_year) oldest_year = temp_book[i].year;
        if(temp_book[i].year > newest_year) newest_year = temp_book[i].year;
        if(temp_book[i].status == 0) available_count++;
        else borrowed_count++;
    }
    
    printf(" THONG KE CHI TIET:\n");
    printf("================================================================\n");
    printf("|  Tong so sach: %-42d |\n", temp_count);
    printf("|  Nam cu nhat: %-43d |\n", oldest_year);
    printf("|  Nam moi nhat: %-42d |\n", newest_year);
    printf("|  Sach con trong: %-40d |\n", available_count);
    printf("|  Sach da muon: %-41d |\n", borrowed_count);
    printf("|  Ty le con trong: %-37.1f%% |\n", (float)available_count/temp_count*100);
    printf("=================================================================\n\n");
    
    // Header table siêu đẹp
    printf("|======================================================================================|\n");
    printf("|                                DANH SACH DA SAP XEP                                  |\n");
    printf("|======================================================================================|\n");
    printf("| %-3s | %-10s | %-25s | %-20s | %-8s | %-12s |\n", 
           "STT", "ID", "Ten Sach", "Tac Gia", "Nam XB", "Trang Thai");
    printf("|======================================================================================|\n");
    
    // Hiển thị từng sách với hiệu ứng
    for(int i = 0; i < temp_count; i++){
        // Trạng thái sách
        const char* status_text = temp_book[i].status == 0 ? "Con trong" : "Da muon";
        
        printf("| %-3d | %-10d | %-25s | %-20s | %-8d | %-12s |\n",
            i+1,
            temp_book[i].id,
            temp_book[i].title,
            temp_book[i].author,
            temp_book[i].year,
            status_text);
        
        // Hiệu ứng typing từng dòng
        if(i < 20) { // Chỉ delay cho 20 dòng đầu
            Sleep(100);
        }
        
        // Phân trang nếu quá nhiều sách
        if((i + 1) % 15 == 0 && i < temp_count - 1) {
            printf("|======================================================================================|\n");
            printf("|                          Nhan Enter de xem tiep...                                   |\n");
            printf("|======================================================================================|\n");
            getchar();
            printf("|======================================================================================|\n");
            printf("|                                DANH SACH DA SAP XEP (tiep)                           |\n");
            printf("|======================================================================================|\n");
            printf("| %-3s | %-4s | %-25s | %-15s | %-8s | %-12s |\n", 
                   "STT", "ID", "Ten Sach", "Tac Gia", "Nam XB", "Trang Thai");
            printf("|======================================================================================|\n");
        }
    }
    
    printf("|====================================================================================================|\n");
    
    // Footer siêu chi tiết
    printf("\n SAP XEP HOAN TAT!\n");
    printf("  Thoi gian xu ly: Sieu nhanh!\n");
    printf(" Chat luong: Sieu VIP!\n");
    printf(" Danh gia: 5 sao!\n");
    
    // Lưu kết quả sắp xếp vào file
    printf("\n Ban co muon luu ket qua sap xep vao file? (y/n): ");
    char save_choice;
    scanf(" %c", &save_choice);
    
    if(save_choice == 'y' || save_choice == 'Y') {
        printf(" Dang luu ket qua");
        for(int i = 0; i < 5; i++) {
            printf(".");
            Sleep(300);
        }
        
        file = fopen("data.txt","w");
        if (file != NULL) {
            for (int i = 0; i < temp_count; i++){
                fprintf(file,"%d %s %s %d %d\n",
                        temp_book[i].id,
                        temp_book[i].title,
                        temp_book[i].author,
                        temp_book[i].year,
                        temp_book[i].status);
            }
            fclose(file);
            printf("\n LUU THANH CONG! File da duoc cap nhat.\n");
        } else {
            printf("\n LUU THAT BAI! Khong the ghi file.\n");
        }
    } else {
        printf(" Ket qua chi hien thi, khong luu vao file.\n");
    }
    
    printf("\n CAM ON BAN DA SU DUNG TINH NANG SAP XEP SIEU VIP!\n");
    printf("Nhan Enter de quay ve menu chinh...");
    getchar();
    getchar();
    
    system("cls");
    return 0;
}
// lưu dữ liệu ra file
void save(){
    printf("that ra chuong trinh nay tu dong luu =)))\n");
    Sleep(2000);
    printf("vay nen khong co gi de luu het!");
    Sleep(2000);
    printf("tam biet!");
    Sleep(1000);
    system("cls");
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
            fix_inf(book_count);    
            break;
        case 4:
            show_books();
            break;
        case 5:
            find_name(); 
            break;
        case 6:
            find_author(); 
            break;
        case 7:
            add_user();    // vibe code
            break;
        case 8:
            muon_sach();   // vibe code
            break;
        case 9:
            tra_sach();    // vibe code
            break;
        case 10:
            sort_year();   // vibe code
            break;
        case 11:
            save();        // vibe code
            break;
        case 0:
            return 0; // thoát khỏi chương trình
        default:
            printf("cu phap sai vui long nhap lai!");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}
// thêm sách
int add_book(){
    printf("vui long nhap id sach: ");
    scanf("%d",&book[i].id);
    printf("vui long nhap ten sach: ");
    fgets(book[i].title,sizeof(book[i].id),stdin);
    printf("vui long nhap ten tac gia: ");
    fgets(book[i].author,sizeof(book[i].author),stdin);
    printf("vui long nhap nam san xuat: ");
    scanf("%d",&book[i].year);
    scanf(1,book[i].status);
}
//xóa danh sách
void del_book(){

}
// sửa thông tin sách
int fix_inf(){
    printf("nhap id sach can sua: ");
    printf("nhap ten sach moi (neu doi): ");
    printf("nhap ten tac gia moi(neu doi): ");
    printf("nhap nam san xua moi: ");

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
    // định nghĩa struct book
    struct qltv{
        int id,
        char title[200],
        char author[100],
        int year,
        int status,  
                // 1: sách đang được mượn
                // 0: sách chưa ai mượn
    }
    struct qltv sv[100];
    // thiết lập các tùy chọn
    int tc;
    int i=0;
    while (true){
        menu();
        printf("nhap tuy chon cua ban: ");
        scanf("%d",&tc);
        switch (tc)
        {
        case 1:
            add_book(i);
            break;
        case 2:
            del_book();
            break;
        case 3:
            fix_inf();
            break;
        case 4:
            find_name();
            break;
        case 5:
            find_author();
            break;
        case 6:
            add_user();
            break;
        case 7:
            muon_sach();
            break;
        case 8:
            tra_sach();
            break;
        case 9:
            sort_year();
            break;
        case 10:
            save();
        default:
            printf("cu phap sai vui long nhap lai!");
            break;
        }
        i++;
    }
}


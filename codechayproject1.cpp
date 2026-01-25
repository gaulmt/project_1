#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Tối đa của sách,chuỗi và số người dùng 
#define MAX_BOOKS 1000
#define MAX_USERS 100
#define MAX_STRING 100
/*project yêu cầu dùng typedef nên bê y nguyên vô code chay được.TRƯỚC KHI NỘP NHỚ XOÁ DÒNG NÀY*/
//Định nghĩa struct book
typedef struct Book {
    int id;
    char title[MAX_STRING];
    char author[MAX_STRING];
    int year;
    char status[20]; // status gồm: Có sẵn & Đã mượn
    struct Book* next;
} Book;
// Định nghĩa struct User(morong1)
typedef struct {
    int id;
    char name[MAX_STRING];
    char borrowed_books[10][MAX_STRING]; // Tối đa 10 sách
    int num_borrowed;
} User;



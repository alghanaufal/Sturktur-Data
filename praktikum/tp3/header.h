// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 3
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char nama[50];
    int harga;
    int kalori;
} sarapan;
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    sarapan kontainer;
    alamatelmt next;
} elemen;
typedef struct
{
    elemen *top;
} stack;

// prosedur membuat stack
void createEmpty(stack *S);
// mengecek apakah ini kosong
int isEmpty(stack S);
// menghitung banyaknya stack
int countElement(stack S);

// menginput stack
void push(int, char[], int, stack *S);
// menghapus stack
void pop(stack *S);
// melalkukan output
void printStack1(stack S);
void printStack2(stack S);

// memindahkan stack sesuai dengan ketentuannya
void popL(stack *S, stack *S1, stack *S2);
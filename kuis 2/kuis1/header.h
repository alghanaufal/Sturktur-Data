// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal Kuis 1
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[101];
    char kode[11];
    char tempat[101];
} nilaiMatKul;

typedef struct
{
    int top;
    nilaiMatKul data[10];
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);

void push(char[], char[], char[], stack *S);
void pop(stack *S);

void printStack(stack S);

void popa(stack S, stack I[], int, char[][101]);
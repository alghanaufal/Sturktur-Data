// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TM 6
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

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);

void push(char[], int, stack *S);
void pop(stack *S);
void printStack1(stack S);
void printStack2(stack S);

void popL(stack *S, stack *I);
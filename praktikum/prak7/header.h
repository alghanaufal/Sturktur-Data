// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TM 7
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char nama[51];
    char nim[51];
} nilaiMatKul;
typedef struct elm *alamatelmt;
typedef struct elm
{
    nilaiMatKul kontainer;
    alamatelmt next;
} elemen;
typedef struct
{
    elemen *first;
    elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char[], char[], queue *Q);
void priority(char[], char[], int, queue *Q);
void del(queue *Q, queue *I);
void printQueue(queue Q);
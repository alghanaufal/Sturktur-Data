// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal kuis 2
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
// library
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[51];
    int ant;
    int smtr;
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

// buat queue
void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);

// input queue
void priority(char[], int, int, queue *Q);
void add(char[], int, int, queue *Q);

// pindah queue
void del(queue *Q, queue *I);
// printQueue
void printQueue(queue Q);
// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TM 3
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[50];
    char nama[50];
    char nilai[10];
} nilaiMatKul;

typedef struct
{
    nilaiMatKul kontainer;
    int prev;
    int next;
} elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(int before, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void printre(list L);
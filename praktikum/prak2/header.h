// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TM 2
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char asalbuku[50];
    char nama[50];
    char jeniskel[2];
} nilaiMatKul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatKul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], char jeniskel[], char asalbuku[], list *L);
void addAfter(elemen *prev, char nama[], char jeniskel[], char asalbuku[], list *L);
void addLast(char nama[], char jeniskel[], char asalbuku[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);

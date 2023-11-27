// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal Kuis soal 1
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char jenis[250];
    char nama[250];
    char harga[250];
} makanan;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    makanan kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);

void addFirst(char jenis[], char nama[], char harga[], list *L);
void addAfter(elemen *prev, char jenis[], char nama[], char harga[], list *L);
void addLast(char jenis[], char nama[], char harga[], list *L);

void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(list L);

elemen *getAddressM(char jenis[], list L);
elemen *getAddressS(char jenis[], list L);
elemen *getPrev(elemen *target, list L);
elemen *getLast(list L);
void swap(elemen *A, elemen *B, list *L1, list *L2);
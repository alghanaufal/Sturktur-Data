// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 2
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */

#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[250];
    int tgl;
    char kode[250];
} barang;
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    barang container;
    alamatelmt prev;
    alamatelmt next;
} elemen;
typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);

void addFirst(char nama[], int tgl, char kode[], list *L);
void addAfter(elemen *before, char nama[], int tgl, char kode[], list *L);
void addBefore(elemen *after, char nama[], int tgl, char kode[], list *L);
void addLast(char nama[], int tgl, char kode[], list *L);

void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(list L);
void printElement_Reverse(list L);

elemen *before(elemen *after, list L);
elemen *pickAfter(elemen *prev, list *L);

// elemen *pickAfter(list *L);
void insertBefore(elemen *prev, elemen *after, list *L);

// void insertBefore(elemen *after, list *L);

void insertionasc(list *L);
void insertiondesc(list *L);

void select(list *L);
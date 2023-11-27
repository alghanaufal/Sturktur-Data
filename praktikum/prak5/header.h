// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TM 5
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char kode[11];
    char nama[51];
} barang;
typedef struct
{
    char brg[51];
} kolom;
typedef struct eklm *alamatekolom;
typedef struct eklm
{
    kolom kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr
{
    barang kontainer;
    eKolom *col;
    alamatebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L);
int countElement(list L);
int countElementK(eBaris L);

void addFirstB(char[], char[], list *L);
void addFirstK(char[], eBaris *L);

void addAfterB(eBaris *prev, char[], char[]);
void addAfterK(eKolom *prev, char[]);

void addLastB(char[], char[], list *L);
void addLastK(char[], eBaris *L);

void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);

void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLast(list *L);
void delAllB(list *L);

void printElement(list L);
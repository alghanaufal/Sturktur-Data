// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal UTS
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char kodep[21];
    char namap[51];
} barang;
typedef struct
{
    char kodeb[21];
    char brg[51];
    int bln;
    int thn;
    char jenis[21];
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
int countElementB(list L);
int countElementK(eBaris L);

void addFirstB(char kodep[], char namap[], list *L);
void addFirstK(char kodeb[], char brg[], int bln, int thn, char jenis[], eBaris *L);

void addAfterB(eBaris *prev, char kodep[], char namap[]);
void addAfterK(eKolom *prev, char kodeb[], char brg[], int bln, int thn, char jenis[]);

void addLastB(char kodep[], char namap[], list *L);
void addLastK(char kodeb[], char brg[], int bln, int thn, char jenis[], eBaris *L);

void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);

void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLast(list *L);
void delAllB(list *L);

void printElement(list L);

void tentu(int blnO, int thnO, eBaris *find, list L);
// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 1
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */

// library yg digunakan
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char judul[101];
    char nama[101];
    int nomor;
} kata; // variable isi kontainer

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    kata kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);                                     // membuat list
int countElement(list L);                                     // menghitung list
void addFirst(char judul[], char nama[], int nomor, list *L); // menambahkan list
void printElement(list L);                                    // print hasil
// sorting dengan bubble
void bubjas(list *L);
void bubjde(list *L);
void bubnas(list *L);
void bubnde(list *L);
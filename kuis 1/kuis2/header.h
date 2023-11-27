// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal Kuis soal 2
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char kode[250];
    char nama[250];
    char jabatan[250];
} staff;

typedef struct
{
    staff kontainer;
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
void addFirst(char kode[], char nama[], char jabatan[], list *L);
void addAfter(int before, char kode[], char nama[], char jabatan[], list *L);
void addLast(char kode[], char nama[], char jabatan[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
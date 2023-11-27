// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TM 1
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char dev[50];
    char nama[50];
    char lvl[10];
} n_matkul;

typedef struct
{
    n_matkul conta;
    int next;
} elemen;

typedef struct
{
    int first;
    elemen data[10];
} list;

void createlist(list *L);
int countelemen(list L);
int emptyelemen(list L);
void addfirst(char nama[], char lvl[], char dev[], list *L);
void addafter(int prev, char nama[], char lvl[], char dev[], list *L);
void addlast(char nama[], char lvl[], char dev[], list *L);
void delfirst(list *L);
void delafter(int prev, list *L);
void dellast(list *L);
void printelemen(list L);
void delall(list *L);
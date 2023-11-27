// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal Tugas Masa Depan
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char nama[201];
    char ortu[201];
    int harga;
    char komponen[201][201];
    int jml;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;
typedef struct
{
    simpul *root;
} tree;
typedef struct
{
    char nama[201];
    char ortu[201];
    int harga;
    char komponen[201][201];
    int inputjml;
} input;

extern int max[201];

void makeTree(char[201], char[201], int, int, char[][201], tree *);
void addchild(char[201], char[201], int, int, char[][201], simpul *);
simpul *findsimpul(char[201], simpul *);

void printTreePreOrder(simpul *, int, int);

void InInput(int, char[201], input[], int);
void InTree(tree *, input[], int);
void spasi(simpul *, int);

void delChild(char[201], simpul *);
void delAll(simpul *);

void findrange(simpul *, int);
void InDell(simpul *, char[201]);
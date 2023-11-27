/*
    Saya Alghaniyu Naufal Hamid 2105673 mengerjakan UAS Soal 1
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// tampungan data
typedef struct
{
    int kiri, kanan;
} data;

// alamat simpul tree
typedef struct smp *alamatsimpul;

// simpul tree
typedef struct smp
{
    data kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

// tree
typedef struct
{
    simpul *root;
} tree;

extern int tampungOutput[100], Idx;

// prosedur dan fungsi
void makeTree(data, tree *);
void addRight(int, simpul *);
void addLeft(int, simpul *);
void delAll(simpul *);
void delRight(simpul *);
void delLeft(simpul *);
void printTreePreOrder(simpul *, simpul *);
void printTreeInOrder(simpul *);
void printTreePostOrder(simpul *, simpul *);
void copyTree(simpul *, simpul **);
int isEqual(simpul *, simpul *);
void addData(int, int kanan, simpul *);
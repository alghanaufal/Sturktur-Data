// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TM 9
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nama[101];
    int nilai;
} data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    data kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(data, tree *T);
void addChild(data, simpul *root);
void delAll(simpul *root);
void delChild(char[], int, simpul *root);
simpul *findSimpul(data, simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
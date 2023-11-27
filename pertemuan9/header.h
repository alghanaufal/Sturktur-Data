/*
    Saya Alghaniyu Naufal Hamid 2105673 mengerjakan UAS Soal 1
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char, tree *T);
void addRight(char, simpul *root);
void addLeft(char, simpul *root);

void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);

void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);

int heightTree(simpul *root);
void printTreeLevelOrder(simpul *root, int);

void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);

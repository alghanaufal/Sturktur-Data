// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 4
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */

// libary
#include <stdio.h>  // input and output
#include <string.h> // libary string
#include <malloc.h> // libary allocation

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer[101];  // kontainer string
    alamatsimpul child;   // alamatsimpul untuk child
    alamatsimpul sibling; // alamatsimpul untuk sibling
} simpul;

typedef struct
{
    simpul *root;
} tree;

void delSimicolon(char[], int);           // presedur hapus ;
simpul *findSimpul(char[], simpul *root); // prosedur mencari simpul

void makeTree(char[], tree *T);      // prosedur membuat pohon
void addChild(char[], simpul *root); // prosedur menambahkan anak

void delChild(char[], simpul *root); // prosedur del anak
void delAll(simpul *root);           // prosedur delAll

// prosedur print
void printTreePreOrder(simpul *root, int);
// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 5
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */

// memanggil library
#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul *first;
} graph;

// presedur buat graph
void createEmpty(graph *);

void addSimpul(char, graph *);          // membuat node
void addJalur(simpul *, simpul *, int); // membuat jalur ke simpulnya

simpul *findSimpul(char, graph); // mencari node

void findTechi(int[], int, int, char, char[], simpul *, graph); // mencari jalur dari techi ke ibunya
void simpan(char[], int, int);                                  // print hasil jalur dari techi ke ibunya
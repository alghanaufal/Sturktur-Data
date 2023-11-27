/*
    Saya Alghaniyu Naufal Hamid 2105673 mengerjakan UAS Soal 2
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
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

void createEmpty(graph *);

void addSimpul(char, graph *);
void addJalur(simpul *, simpul *);

simpul *findSimpul(char, graph);
void delJalur(char, simpul *);
void delAll(simpul *);
void delSimpul(char, graph *);
void printGraph(graph);

void findTechi(graph, char, char);
void bfs(graph, char, char);
void cekGraph(graph G, simpul *node);
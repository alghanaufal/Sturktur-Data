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
void addJalur(simpul *, simpul *, int);
simpul *findSimpul(char, graph);
void delJalur(char, simpul *);
void delAll(simpul *);
void delSimpul(char, graph *);
void printGraph(graph);
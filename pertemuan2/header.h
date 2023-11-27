#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    char nilai[2];
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
void addfirst(char nim[], char nama[], char nilai[], list *L);
void addafter(int prev, char nim[], char nama[], char nilai[], list *L);
void addlast(char nim[], char nama[], char nilai[], list *L);
void delfirst(list *L);
void delafter(int prev, list *L);
void dellast(list *L);
void printelemen(list L);
void delall(list *L);
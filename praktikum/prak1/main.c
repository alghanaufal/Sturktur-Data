// /*
// Saya Alghaniyu Naufal Hamid lvl 2105673 mengerjakan soal TM 1
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */

#include <stdio.h>
#include <string.h>

#include "header.h"

int main()
{
    list L;
    char dev[50];
    char nama[50];
    char lvl[10];
    createlist(&L);
    scanf("%s %s %s", nama, lvl, dev);
    addfirst(nama, lvl, dev, &L);
    scanf("%s %s %s", nama, lvl, dev);
    addfirst(nama, lvl, dev, &L);
    scanf("%s %s %s", nama, lvl, dev);
    addafter(L.first, nama, lvl, dev, &L);
    printelemen(L);
    printf("--------------------\n");
    dellast(&L);
    scanf("%s %s %s", nama, lvl, dev);
    addafter(L.data[L.first].next, nama, lvl, dev, &L);
    scanf("%s %s %s", nama, lvl, dev);
    addlast(nama, lvl, dev, &L);
    printelemen(L);
    printf("--------------------\n");
    delafter(L.data[L.first].next, &L);
    delfirst(&L);
    dellast(&L);
    printelemen(L);
    printf("--------------------\n");
    dellast(&L);
    printelemen(L);
    printf("--------------------\n");
    return 0;
}
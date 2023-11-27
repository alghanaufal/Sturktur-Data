#include "header.h"

int main()
{
    char nama[256];
    char nim[256];
    char gol[256];
    list L;
    createList(&L);
    printf("Data Golongan Darah\n===================\n");

    scanf("%s %s %s", &nama, &nim, &gol);
    addLast(nama, nim, gol, &L);
    scanf("%s %s %s", &nama, &nim, &gol);
    addFirst(nama, nim, gol, &L);
    scanf("%s %s %s", &nama, &nim, &gol);
    addBefore(L.first->next, nama, nim, gol, &L);
    printElement(L);
    printf("===================\n");

    scanf("%s %s %s", &nama, &nim, &gol);
    addAfter(L.first->next, nama, nim, gol, &L);
    delAfter(L.first, &L);
    scanf("%s %s %s", &nama, &nim, &gol);
    addAfter(L.first, nama, nim, gol, &L);
    scanf("%s %s %s", &nama, &nim, &gol);
    addBefore(L.tail, nama, nim, gol, &L);
    delFirst(&L);
    printElement(L);
    printf("===================\n");

    delLast(&L);
    delAfter(L.first, &L);
    scanf("%s %s %s", &nama, &nim, &gol);
    addLast(nama, nim, gol, &L);
    printElement_Reverse(L);
    printf("===================\n");

    delAll(&L);
    printElement(L);

    return 0;
}
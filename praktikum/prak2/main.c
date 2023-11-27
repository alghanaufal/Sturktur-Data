#include "header.h"

int main()
{
    list L;
    char asalbuku[50];
    char nama[50];
    char jeniskel[10];
    createList(&L);
    scanf("%s %s %s", nama, jeniskel, asalbuku);
    addLast(nama, jeniskel, asalbuku, &L);
    scanf("%s %s %s", nama, jeniskel, asalbuku);
    addFirst(nama, jeniskel, asalbuku, &L);
    scanf("%s %s %s", nama, jeniskel, asalbuku);
    addAfter(L.first->next, nama, jeniskel, asalbuku, &L);
    printf("--------------------\n");
    printElement(L);
    printf("--------------------\n");
    delAfter(L.first->next, &L);
    delFirst(&L);
    printElement(L);
    printf("--------------------\n");
    scanf("%s %s %s", nama, jeniskel, asalbuku);
    addLast(nama, jeniskel, asalbuku, &L);
    scanf("%s %s %s", nama, jeniskel, asalbuku);
    addFirst(nama, jeniskel, asalbuku, &L);
    delLast(&L);
    printElement(L);
    printf("--------------------\n");
    delAll(&L);
    printElement(L);
    printf("--------------------\n");
    scanf("%s %s %s", nama, jeniskel, asalbuku);
    addLast(nama, jeniskel, asalbuku, &L);
    printElement(L);
    printf("--------------------\n");
    return 0;
}
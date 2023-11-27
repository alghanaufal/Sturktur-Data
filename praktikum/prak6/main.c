#include "header.h"

int main()
{
    stack S1;
    stack S2;

    char nama[51];
    int harga;

    createEmpty(&S1);
    createEmpty(&S2);

    printStack1(S1);
    printStack2(S2);
    printf("==================\n");

    scanf("%s %d", nama, &harga);
    push(nama, harga, &S1);

    scanf("%s %d", nama, &harga);
    push(nama, harga, &S2);
    scanf("%s %d", nama, &harga);
    push(nama, harga, &S2);

    printStack1(S1);
    printStack2(S2);
    printf("==================\n");

    pop(&S1);
    popL(&S2, &S1);

    scanf("%s %d", nama, &harga);
    push(nama, harga, &S1);

    scanf("%s %d", nama, &harga);
    push(nama, harga, &S2);

    scanf("%s %d", nama, &harga);
    push(nama, harga, &S1);

    pop(&S2);
    popL(&S1, &S2);

    printStack1(S1);
    printStack2(S2);
    printf("==================\n");

    return 0;
}
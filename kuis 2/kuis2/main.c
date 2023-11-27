#include "header.h"

int main()
{
    // inisiasi
    int n = 0;
    int x = 0;

    // var input
    char nama[101];
    int ant,
        smtr;

    // var queue
    queue Q1;
    queue Q2;

    // buat queue
    createEmpty(&Q1);
    createEmpty(&Q2);

    scanf("%d", &n);

    // input queue
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &nama);
        scanf("%d %d", &ant, &smtr);
        // buat priority
        priority(nama, ant, smtr, &Q1);
    }
    // printQueue(Q1);

    // input yg sudah dapat
    scanf("%d", &x);
    // masukan yg sudah dapat beasiswa
    for (int j = 0; j < x; j++)
    {
        del(&Q1, &Q2);
    }

    // print hasil
    printf("sudah mendapat beasiswa:\n");
    printQueue(Q2);

    printf("belum mendapat beasiswa:\n");
    printQueue(Q1);

    return 0;
}
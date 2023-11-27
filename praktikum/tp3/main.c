#include "header.h"

int main()
{
    // buat var stack
    stack S1; // stack keseluruhan
    stack S2; // stack makanan pedas
    stack S3; // stack makanan manis

    // buat stack
    createEmpty(&S1); // buat stack keeseeluruhan
    createEmpty(&S2); // buat stack makanan manis
    createEmpty(&S3); // buat stack makanan pedas

    // meenentukan banyaknya stack
    int n = 0;
    scanf("%d", &n);
    char nama[51]; // var nama makanan
    int harga,     // var harga makanan
        kalori;    // var kalori makanan

    for (int i = 0; i < n; i++) // lakukan looping
    {
        scanf("%d %s %d", &harga, &nama, &kalori); // input
        push(harga, nama, kalori, &S1);            // push ke stack keseluruhan
    }
    popL(&S1, &S2, &S3); // lakukan penyeleksian

    printStack1(S2); // print makanan pedas
    printf("\n");
    printStack2(S3); // print makanan manis

    return 0; // akhir program
}
#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = -1;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S)
{
    int hasil = 0;
    if (S.top == 100)
    {
        hasil = 1;
    }
    return hasil;
}

void push(char nama[], char kode[], char tempat[], stack *S)
{

    if (isFull(*S) == 1)
    {
        /*jika stack penuh*/
        printf("stack penuh\n");
    }
    else
    {
        if (isEmpty(*S) == 1)
        {
            /* jika stack kosong */
            (*S).top = 0;
            strcpy((*S).data[0].nama, nama);
            strcpy((*S).data[0].kode, kode);
            strcpy((*S).data[0].tempat, tempat);
        }
        else
        {
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].nama, nama);
            strcpy((*S).data[(*S).top].kode, kode);
            strcpy((*S).data[(*S).top].tempat, tempat);
        }
    }
}

void pop(stack *S)
{

    if ((*S).top == 0)
    {
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1)
        {
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}

void printStack(stack S)
{
    if (S.top != -1)
    {
        for (int i = S.top; i >= 0; i--)
        {
            printf("- %s", S.data[i].nama);
            printf(" %s", S.data[i].kode);
            printf(" %s\n", S.data[i].tempat);
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}

void popa(stack S, stack I[], int x, char tempat[][101])
{
    while (S.top != -1)
    {
        for (int j = 0; j < x; j++)
        {
            if (strcmp(S.data[S.top].tempat, tempat[j]) == 0)
            {
                push(S.data[S.top].nama, S.data[S.top].kode, S.data[S.top].tempat, &I[j]);
                pop(&S);
            }
        }
    }
}

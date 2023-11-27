#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = NULL;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S)
{

    int hasil = 0;

    if (S.top != NULL)
    {
        /* stack tidak kosong */

        elemen *bantu;

        /* inisialisasi */
        bantu = S.top;
        while (bantu != NULL)
        {
            /* proses */
            hasil++;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(char nama[], int harga, stack *S)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;
    if ((*S).top == NULL)
    {
        // jika stack kosong
        baru->next = NULL;
    }
    else
    {
        // jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S)
{
    if ((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
}

void popL(stack *S, stack *I)
{
    if ((*S).top != NULL)
    {
        // jika stack bukan list kosong
        elemen *hapus = (*S).top;
        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        push(hapus->kontainer.nama, hapus->kontainer.harga, I);
        free(hapus);
    }
}

void printStack1(stack S)
{
    printf("S1:\n");
    if (S.top != NULL)
    {
        int i = 1;
        elemen *bantu = S.top;

        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Stack Kosong\n");
    }
}

void printStack2(stack S)
{
    printf("S2:\n");
    if (S.top != NULL)
    {
        int i = 1;
        elemen *bantu = S.top;

        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Stack Kosong\n");
    }
}
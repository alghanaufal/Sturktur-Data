#include "header.h"

void createEmpty(queue *Q)
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q)
{
    int hasil = 0;
    if (Q.first != NULL)
    {
        /* queue tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = Q.first;

        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }

    return hasil;
}

void add(char nama[], int ant, int smtr, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.ant = ant;
    baru->kontainer.smtr = smtr;

    baru->next = NULL;

    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }

    (*Q).last = baru;
    baru = NULL;
}

void priority(char nama[], int ant, int smtr, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.ant = ant;
    baru->kontainer.smtr = smtr;

    baru->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
        (*Q).last = baru;
    }
    else
    {
        if (ant == 1)
        {
            baru->next = (*Q).first;
            (*Q).first = baru;
        }
        else if (ant > countElement(*Q))
        {
            add(nama, ant, smtr, Q);
        }
        else
        {
            elemen *bantu = (*Q).first;
            int i = 1;
            while (bantu != NULL)
            {
                if (i == ant - 1)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                bantu = bantu->next;
                i++;
            }
        }
    }
    baru = NULL;
}

void del(queue *Q, queue *I)
{
    if ((*Q).first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *hapus = (*Q).first;
        if (countElement(*Q) == 1)
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else
        {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        add(hapus->kontainer.nama, hapus->kontainer.ant, hapus->kontainer.smtr, I);
        // free(hapus);
    }
}

void printQueue(queue Q)
{
    if (Q.first != NULL)
    {
        elemen *bantu = Q.first;
        while (bantu != NULL)
        {
            printf("%s", bantu->kontainer.nama);
            printf(" %d %d\n", bantu->kontainer.ant, bantu->kontainer.smtr);
            /* iterasi */
            bantu = bantu->next;
        }
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}
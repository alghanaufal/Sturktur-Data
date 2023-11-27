#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        // list tidak kosong
        elemen *tunjuk;

        // inisialisasi
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            // proses
            hasil++;

            // iterasi
            tunjuk = tunjuk->next;
        }
    }

    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    if ((*L).first == NULL)
    {
        baru->next = NULL;
        baru->prev = NULL;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *before, char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    if (before->next == NULL)
    {
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = before->next;
        baru->next->prev = baru;
    }
    baru->prev = before;
    before->next = baru;
    baru = NULL;
}

void addLast(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == NULL)
    {
        // jika list adalah list kosong
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        addAfter((*L).tail, nim, nama, nilai, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        // jika list bukan list kosong
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first->prev = NULL;
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    elemen *hapus = before->next;
    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            before->next = NULL;
        }
        else
        {
            before->next = hapus->next;
            hapus->next->prev = before;
            hapus->next = NULL;
        }
        hapus->prev = NULL;
        free(hapus);
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        // jika list tidak kosong
        if (countElement(*L) == 1)
        {
            // list terdiri dari satu elemen
            delFirst(L);
        }
        else
        {
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        // jika list tidak kosong
        // inisialisasi
        elemen *tunjuk = L.first;
        int i = 1;

        while (tunjuk != NULL)
        {
            // proses
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", tunjuk->kontainer.nim);
            printf("nama : %s\n", tunjuk->kontainer.nama);
            printf("nilai : %s\n", tunjuk->kontainer.nilai);
            printf("-------------\n");

            // iterasi
            tunjuk = tunjuk->next;
            i++;
        }
    }
    else
    {
        // proses jika list kosong
        printf("list kosong\n");
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        int i;

        for (i = countElement(*L); i >= 1; i--)
        {
            // proses menghapus elemen list
            delLast(L);
        }
    }
}

void tukar(list *L)
{
    elemen *pnext;
    elemen *ptail;

    pnext = (*L).first;
    ptail = (*L).tail;
    char nama[51],
        nim[51],
        nilai[5];

    for (int i = 0; i < (countElement(*L) / 2); i++)
    {
        strcpy(nim, pnext->kontainer.nim);
        strcpy(nama, pnext->kontainer.nama);
        strcpy(nilai, pnext->kontainer.nilai);

        strcpy(pnext->kontainer.nim, ptail->kontainer.nim);
        strcpy(pnext->kontainer.nama, ptail->kontainer.nama);
        strcpy(pnext->kontainer.nilai, ptail->kontainer.nilai);

        strcpy(ptail->kontainer.nim, nim);
        strcpy(ptail->kontainer.nama, nama);
        strcpy(ptail->kontainer.nilai, nilai);

        pnext = pnext->next;
        ptail = pnext->prev;
    }
}
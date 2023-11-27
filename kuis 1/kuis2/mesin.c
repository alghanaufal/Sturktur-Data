#include "header.h"

void createList(list *L)
{

    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int bantu;
        bantu = L.first;
        while (bantu != -1)
        {
            hasil = hasil + 1;
            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

int emptyElement(list L)
{
    int hasil = -1;
    if (countElement(L) < 10)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 10))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst(char kode[], char nama[], char jabatan[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kode, kode);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.jabatan, jabatan);

        if ((*L).first == -1)
        {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }

        else
        {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }
        (*L).first = baru;
    }
    else
    {
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char kode[], char nama[], char jabatan[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);

        strcpy((*L).data[baru].kontainer.kode, kode);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.jabatan, jabatan);
        if ((*L).data[before].next != -1)
        {
            (*L).data[baru].prev = before;
            (*L).data[baru].next = (*L).data[before].next;
            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].prev = baru;
        }
        else
        {
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    }
    else
    {
        printf("sudah tidak dapat ditambah\n");
    }
}

void addLast(char kode[], char nama[], char jabatan[], list *L)
{
    if ((*L).first == -1)
    {
        addFirst(kode, nama, jabatan, L);
    }
    else
    {
        addAfter((*L).tail, kode, nama, jabatan, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = -1;
            (*L).tail = -1;
        }
        else
        {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
    else
    {
        printf("list kosong\n");
    }
}

void delAfter(int before, list *L)
{
    int hapus = (*L).data[before].next;
    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).tail = before;
            (*L).data[before].next = -1;
        }
        else
        {
            (*L).data[before].next = (*L).data[hapus].next;
            (*L).data[(*L).data[hapus].next].prev = before;
        }
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L)
{

    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            delAfter((*L).data[(*L).tail].prev, L);
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

// void printElement(list L)
// {
//     if (L.first != -1)
//     {
//         int bantu = L.first;
//         while (bantu != -1)
//         {
//             printf("%s", L.data[bantu].kontainer.kode);
//             printf(" %s", L.data[bantu].kontainer.nama);
//             printf(" %s\n", L.data[bantu].kontainer.jabatan);
//             bantu = L.data[bantu].next;
//             bantu = L.data[bantu].next;
//         }
//     }
//     else
//     {
//         printf("list kosong\n");
//     }
// }

void printElement(list L)
{
    if (L.tail != -1)
    {
        int bantu = L.tail;
        while (bantu != -1)
        {
            printf("%s", L.data[bantu].kontainer.kode);
            printf(" %s", L.data[bantu].kontainer.nama);
            printf(" %s\n", L.data[bantu].kontainer.jabatan);
            bantu = L.data[bantu].prev;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        delLast(L);
    }
}

void tuker(list *L)
{
    int depan = (*L).first;
    int belakang = (*L).tail;
}
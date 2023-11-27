#include "header.h"

void createlist(list *L)
{
    (*L).first = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        (*L).data[i].next = -2;
    }
}

int countelemen(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int hitung;
        hitung = L.first;

        while (hitung != -1)
        {
            {
                hasil++;

                hitung = L.data[hitung].next;
            }
        }
        return hasil;
    }
}
int emptyelemen(list L)
{
    int hasil = -1;

    if (countelemen(L) < 10)
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
                i++;
            }
        }
    }
    return hasil;
}

void addfirst(char nama[], char lvl[], char dev[], list *L)
{
    if (countelemen(*L) < 10)
    {
        int baru = emptyelemen(*L);
        strcpy((*L).data[baru].conta.nama, nama);
        strcpy((*L).data[baru].conta.lvl, lvl);
        strcpy((*L).data[baru].conta.dev, dev);

        if ((*L).first == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            (*L).data[baru].next = (*L).first;
        }
        (*L).first = baru;
    }
    else
    {
        printf("sudah tidak dpt ditambah\n");
    }
}

void addafter(int prev, char nama[], char lvl[], char dev[], list *L)
{
    if (countelemen(*L) < 10)
    {
        int baru = emptyelemen(*L);
        strcpy((*L).data[baru].conta.nama, nama);
        strcpy((*L).data[baru].conta.lvl, lvl);
        strcpy((*L).data[baru].conta.dev, dev);

        if ((*L).data[prev].next == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    }
    else
    {
        printf("sudah tidak dpt ditambah\n");
    }
}

void addlast(char dev[], char nama[], char lvl[], list *L)
{
    if ((*L).first == -1)
    {
        addfirst(dev, nama, lvl, L);
    }
    else
    {
        if (countelemen(*L) < 10)
        {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1)
            {
                prev = (*L).data[prev].next;
            }
            addafter(prev, dev, nama, lvl, L);
        }
        else
        {
            printf("sudah tidak dpt ditambah\n");
        }
    }
}

void delfirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (countelemen(*L) == 1)
        {
            (*L).first = -1;
        }
        else
        {
            (*L).first = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void delafter(int prev, list *L)
{
    int hapus = (*L).data[prev].next;

    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).data[prev].next = -1;
        }
        else
        {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
}

void dellast(list *L)
{
    if ((*L).first != -1)
    {
        if (countelemen(*L) == 1)
        {
            delfirst(L);
        }
        else
        {
            int hapus = (*L).first;
            int prev;
            while ((*L).data[hapus].next != -1)
            {
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            delafter(prev, L);
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void printelemen(list L)
{
    if (L.first != -1)
    {
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1)
        {
            printf("- %s", L.data[tunjuk].conta.nama);
            printf(" %s", L.data[tunjuk].conta.lvl);
            printf(" %s\n", L.data[tunjuk].conta.dev);
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void delall(list *L)
{
    int i;
    for (i = countelemen(*L); i >= 1; i--)
    {
        dellast(L);
    }
}
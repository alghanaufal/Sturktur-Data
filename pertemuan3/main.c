#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nim[10];
    char nama[50];
    char nilai[2];
} n_matkul;

typedef struct elm *alamatelmt;
typedef struct elm
{
    n_matkul kont;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createlist(list *L)
{
    (*L).first = NULL;
}

int countelemen(list L)
{
    int hasil = 0;

    if (L.first != NULL)
    {
        elemen *tunjuk;
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            hasil++;
            tunjuk = tunjuk->next;
        }
    }

    return hasil;
}

void addfirst(char nim[], char nama[], char nilai[], list *L)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen));
    strcpy(new->kont.nim, nim);
    strcpy(new->kont.nama, nama);
    strcpy(new->kont.nilai, nilai);

    if ((*L).first == NULL)
    {
        new->next = NULL;
    }
    else
    {
        (*L).first = new->next;
    }
    (*L).first = new;
    new = NULL;
}

void addafter(elemen *prev, char nim[], char nama[], char nilai[], list *L)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen));
    strcpy(new->kont.nim, nim);
    strcpy(new->kont.nama, nama);
    strcpy(new->kont.nilai, nilai);

    if (prev->next == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

void addlast(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == NULL)
    {
        addfirst(nim, nama, nilai, L);
    }
    else
    {
        elemen *prev = (*L).first;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        addafter(prev, nim, nama, nilai, L);
    }
}

void delfirst(list *L)
{
    if ((*L).first == NULL)
    {
        elemen *hapus = (*L).first;
        if (countelemen(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delafter(elemen *prev, list *L)
{
    elemen *hapus = prev->next;
    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void dellast(list *L)
{
    if ((*L).first != NULL)
    {
        if (countelemen(*L) == 1)
        {
            delfirst(L);
        }
        else
        {
            elemen *last = (*L).first;
            elemen *prev;
            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }
            delafter(prev, L);
        }
    }
}

void delall(list *L)
{
    if (countelemen(*L) != 0)
    {
        int i;
        for (i = countelemen(*L); i >= 1; i--)
        {
            dellast(L);
        }
    }
}

void printelemen(list L)
{
    if (L.first != NULL)
    {
        elemen *tunjuk = L.first;
        int i = 1;
        while (tunjuk != NULL)
        {
            printf("elemen  : %d\n", i);
            printf("NIM     : %s\n", tunjuk->kont.nim);
            printf("Nama    : %s\n", tunjuk->kont.nama);
            printf("Nilai   : %s\n", tunjuk->kont.nilai);
            printf("------------\n");

            tunjuk = tunjuk->next;
            i++;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

int main()
{
    list L;
    createlist(&L);
    printelemen(L);
    printf("====================\n");

    addfirst("1", "orang_1", "A", &L);
    addafter(L.first, "2", "orang_2", "A", &L);
    addlast("3", "orang_3", "A", &L);
    printelemen(L);

    printf("====================\n");

    dellast(&L);
    delafter(L.first, &L);
    delfirst(&L);
    printelemen(L);

    printf("====================\n");

    return 0;
}
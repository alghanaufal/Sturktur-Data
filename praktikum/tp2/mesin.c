// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 2
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */

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
        elemen *bantu;

        bantu = L.first;
        while (bantu != NULL)
        {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nama[], int tgl, char kode[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->container.nama, nama);
    baru->container.tgl = tgl;
    strcpy(baru->container.kode, kode);
    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
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

void addAfter(elemen *before, char nama[], int tgl, char kode[], list *L)
{
    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->container.nama, nama);
        baru->container.tgl = tgl;
        strcpy(baru->container.kode, kode);
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
}

void addBefore(elemen *after, char nama[], int tgl, char kode[], list *L)
{
    if (after != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->container.nama, nama);
        baru->container.tgl = tgl;
        strcpy(baru->container.kode, kode);
        if (after->prev == NULL)
        {
            baru->prev = NULL;
            (*L).first = baru;
        }
        else
        {
            baru->prev = after->prev;
            baru->prev->next = baru;
        }
        baru->next = after;
        after->prev = baru;
        baru = NULL;
    }
}

void addLast(char nama[], int tgl, char kode[], list *L)
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(nama, tgl, kode, L);
    }
    else
    {
        /*jika list tidak kosong*/
        addAfter((*L).tail, nama, tgl, kode, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
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
            L->tail = before;
            before->next = NULL;
        }
        else
        {
            before->next = hapus->next;
            hapus->next->prev = before;
        }
        hapus->prev = NULL;
        hapus->next = NULL;
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            delAfter((*L).tail->prev, L);
        }
    }
    else
    {
        printf("List Kosong\n");
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        int i;
        for (i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}

void printElement(list L)
{
    if (L.tail != NULL)
    {
        elemen *bantu = L.tail;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s %s\n", bantu->container.kode, bantu->container.nama);
            bantu = bantu->prev;
            i++;
        }
    }
    else
    {
        printf("List Kosong\n");
    }
}

void printElement_Reverse(list L)
{
    if (L.tail != NULL)
    {
        elemen *bantu = L.tail;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s Telah dihapus.\n", bantu->container.kode);
            bantu = bantu->prev;
            i++;
        }
    }
    else
    {
        printf("List Kosong\n");
    }
}

elemen *before(elemen *after, list L)
{
    if (after == L.first)
    {
        return NULL;
    }
    else
    {
        elemen *before = L.first;
        while (before->next != after)
        {
            before = before->next;
        }
        return before;
    }
}

elemen *pickAfter(elemen *prev, list *L)
{
    elemen *pick = prev->next;
    if (pick != NULL)
    {
        if (pick->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = pick->next;
            pick->next = NULL;
        }
    }
    return pick;
}

// elemen *pickAfter(list *L)
// {
//     elemen *pick;
//     if (pick != NULL)
//     {
//         if (pick->prev == NULL)
//         {
//             pick->next = NULL;
//         }
//         else
//         {
//             pick->prev = NULL;
//         }
//     }
// }

void insertBefore(elemen *prev, elemen *after, list *L)
{
    elemen *in = pickAfter(prev, &(*L));

    in->next = after;
    if ((*L).first == after)
    {
        (*L).first = in;
    }
    else
    {
        before(after, (*L))->next = in;
    }
    in = NULL;
}

// void insertBefore(elemen *after, list *L)
// {
//     elemen *in = pickAfter(&(*L));

//     in->prev = after;
//     if ((*L).first == after)
//     {
//         (*L).first = in;
//     }
//     else
//     {
//         (*L).tail = in;
//     }
//     in = NULL;
// }

void insertionasc(list *L)
{
    elemen *i;
    int done;

    elemen *j = (*L).first;
    while (j->next != NULL)
    {
        done = 0;
        i = (*L).first;
        while ((i != j->next) && (done == 0))
        {
            if (strcmp(i->container.kode, j->next->container.kode) > 0)
            {
                elemen *tmp = j->next;
                // insertBefore(i, &(*L));
                insertBefore(j, i, &(*L));
                j = tmp;
                done = 1;
            }
            i = i->next;
        }
        j = j->next;
    }
}

void insertiondesc(list *L)
{
    elemen *i;
    int done;

    elemen *j = (*L).first;
    while (j->next != NULL)
    {
        done = 0;
        i = (*L).first;
        while ((i != j->next) && (done == 0))
        {
            if (i->container.tgl > j->next->container.tgl)
            {
                elemen *tmp = j->next;
                // insertBefore(i, &(*L));
                insertBefore(j, i, &(*L));
                j = tmp;
                done = 1;
            }
            i = i->next;
        }
        j = j->next;
    }
}

void select(list *L)
{
    // if (L->first != NULL)
    // {
    list Lx;
    createList(&Lx);
    list Ly;
    createList(&Ly);
    elemen *i = L->first;
    while (i != NULL)
    {
        if (i->container.tgl % 5 == 0)
        {
            // printf("apusni\n");
            // delFirst(L);
            addFirst(i->container.nama, i->container.tgl, i->container.kode, &Lx);
        }
        else if (i->container.tgl % 5 != 0)
        {

            addFirst(i->container.nama, i->container.tgl, i->container.kode, &Ly);
        }
        i = i->next;
    }
    // delAll(L);
    insertionasc(&Lx);
    printElement_Reverse(Lx);
    delAll(&Lx);
    printf("==== List Barang ====\n");
    insertiondesc(&Ly);
    printElement(Ly);
    printf("=====================\n");
    // }

    // else
    // {
    //     printf("List Kosong\n");
    // }
}
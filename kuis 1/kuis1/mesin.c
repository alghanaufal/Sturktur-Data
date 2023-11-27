#include "header.h"

void createList(list *L)
{
    L->first = NULL;
}

int countElement(list L)
{
    int result = 0;

    if (L.first != NULL)
    {
        elemen *temp;
        temp = L.first;

        while (temp != NULL)
        {
            result++;
            temp = temp->next;
        }
    }
    return result;
}

void addFirst(char jenis[], char nama[], char harga[], list *L)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen));

    strcpy(new->kontainer.nama, jenis);
    strcpy(new->kontainer.nama, nama);
    strcpy(new->kontainer.harga, harga);

    if (L->first == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = L->first;
    }

    L->first = new;
    new = NULL;
}

void addAfter(elemen *prev, char jenis[], char nama[], char harga[], list *L)
{
    elemen *new;
    new = (elemen *)malloc(sizeof(elemen));

    strcpy(new->kontainer.nama, jenis);
    strcpy(new->kontainer.nama, nama);
    strcpy(new->kontainer.harga, harga);

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

void addLast(char jenis[], char nama[], char harga[], list *L)
{
    if (L->first == NULL)
    {
        addFirst(jenis, nama, harga, L);
    }
    else
    {
        elemen *prev = L->first;

        while (prev->next != NULL)
        {
            prev = prev->next;
        }

        addAfter(prev, jenis, nama, harga, L);
    }
}

void delFirst(list *L)
{
    if (L->first != NULL)
    {
        elemen *del = L->first;

        if (countElement(*L) == 1)
        {
            L->first = NULL;
        }
        else
        {
            L->first = L->first->next;
            del->next = NULL;
        }

        free(del);
    }
}

void delAfter(elemen *prev, list *L)
{
    elemen *del = prev->next;

    if (del != NULL)
    {
        if (del->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = del->next;
            del->next = NULL;
        }

        free(del);
    }
}

void delLast(list *L)
{
    if (L->first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            elemen *del = L->first;
            elemen *prev;

            while (del->next != NULL)
            {
                prev = del;
                del = del->next;
            }
            delAfter(prev, L);
        }
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        for (int i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        elemen *temp = L.first;
        int i = 1;

        while (temp != NULL)
        {
            printf("%s %s %s\n", temp->kontainer.jenis, temp->kontainer.nama, temp->kontainer.harga);

            temp = temp->next;
            i++;
        }
    }
    else
    {
        printf("list Kosong.\n");
    }
}

elemen *getAddressM(char jenis[], list L) // fungsi untuk mencari pointer elemen dari jenis yang dimasukkan
{
    elemen *curr = L.first; // curr mulai dari elemen pertama

    while (curr != NULL) // loop sampai akhir list
    {
        if (strcmp(curr->kontainer.jenis, jenis) == 0) // jika nama di pointer curr sama dengan nama yang dicari
        {
            return curr; // return pointer ini (curr)
            break;       // sekaligus keluar dari loop
        }
        curr = curr->next; // jika bukan pointer akan pindah ke elemen selanjutnya
    }

    return NULL; // jika loop tidak menemukan nama yang sama, maka fungsi akan mereturn NULL
}

elemen *getAddressS(char jenis[], list L) // fungsi untuk mencari pointer elemen dari jenis yang dimasukkan
{
    elemen *curr = L.first; // curr mulai dari elemen pertama

    while (curr != NULL) // loop sampai akhir list
    {
        if (strcmp(curr->kontainer.jenis, jenis) == 0) // jika nama di pointer curr sama dengan nama yang dicari
        {
            return curr; // return pointer ini (curr)
            break;       // sekaligus keluar dari loop
        }
        curr = curr->next; // jika bukan pointer akan pindah ke elemen selanjutnya
    }

    return NULL; // jika loop tidak menemukan nama yang sama, maka fungsi akan mereturn NULL
}

elemen *getLast(list L) // fungsi untuk mendapatkan pointer elemen terakhir dari list
{
    elemen *curr = L.first; // curr mulai dari elemen pertama

    while (curr->next != NULL) // loop sampai elemen kedua terakhir dari list
    {
        curr = curr->next; // pindah ke elemen berikutnya
    }

    return curr; // return nilai curr
}

elemen *getPrev(elemen *target, list L) // fungsi untuk mencari elemen sebelumnya
{
    elemen *prev = L.first; // inisialisasi prev ke elemen pertama

    if (target == L.first) // jika target merupakan elemen pertama
    {
        return NULL; // artinya tidak ada prev
    }
    while (prev->next != target) // jika bukan elemen pertama fungsi akan dilanjutkan
    {
        prev = prev->next; // hingga pointer next merupakan target
    }
    return prev; // kembalikan prev
}

void swap(elemen *A, elemen *B, list *L1, list *L2) // fungsi untuk menukar pointer dua elemen A dan B
{
    elemen *prev1 = getPrev(A, *L1); // cari elemen yang menunjuk/sebelum elemen A
    elemen *prev2 = getPrev(B, *L2); // cari elemen yang menunjuk/sebelum elemen B

    elemen *last1 = getLast(*L1); // cari elemen terakhir dari list 1
    elemen *last2 = getLast(*L2);

    if (A == last1) // jika A elemen terakhir dari list 1
    {
        prev1->next = B; // set pointer next elemen sebelum A ke B
    }
    else // jika bukan
    {
        last1->next = B; // set pointer next elemen terakhir dari list 1 ke B
    }
    if (B == last2) // jika B elemen terakhir dari list 2
    {
        prev2->next = A; // set pointer next elemen sebelum B ke A
    }
    else // jika bukan
    {
        last2->next = A; // set pointer next elemen terakhir dari list 2 ke A
    }

    if (prev1 == NULL) // jika A merupakan elemen pertama dari list 1
    {
        L1->first = A->next; // set pointer first list pertama ke elemen setelah A
    }
    else if (A != last1) // jika A bukan elemen pertama dan terakhir dari list 1
    {
        prev1->next = A->next; // set pointer next elemen sebelum A ke elemen sesudah A
    }
    if (prev2 == NULL) // jika B merupakan elemen pertama dari list 2
    {
        L2->first = B->next; // set pointer first list kedua ke elemen setelah B
    }
    else if (B != last2) // jika B bukan elemen pertama dan terakhir dari list 2
    {
        prev2->next = B->next; // set pointer next elemen sebelum B ke elemen sesudah B
    }

    // karena setelah ditukar kedua elemen berada di akhir list, maka set pointer next kedua elemen ke NULL
    A->next = NULL;
    B->next = NULL;
}
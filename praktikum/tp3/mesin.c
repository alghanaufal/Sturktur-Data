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

void push(int harga, char nama[], int kalori, stack *S)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    baru->kontainer.harga = harga;
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.kalori = kalori;

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

void popL(stack *S, stack *S1, stack *S2)
{
    if ((*S).top != NULL)
    {
        elemen *bagi = (*S).top; // var stack dari atas
        while (bagi != NULL)
        {
            int temp = 0;                                          // menyimpan hasil penjumlahan string
            for (int j = 0; j < strlen(bagi->kontainer.nama); j++) // lakukan looping sepanjang kata
            {
                temp += bagi->kontainer.nama[j]; // ditambahkan
            }

            if (temp % 2 == 0) // bila hasilnya genap
            {
                push(bagi->kontainer.harga, bagi->kontainer.nama, bagi->kontainer.kalori, S1); // push ke makanan pedas
            }
            else // bila hasilnya ganjil
            {
                push(bagi->kontainer.harga, bagi->kontainer.nama, bagi->kontainer.kalori, S2); // push ke makanan manis
            }
            bagi = bagi->next; // ingkremenkan
        };
    }
}

// proseedur print
void printStack1(stack S)
{
    printf("Wishlist Makanan Pedas:\n===================\n");
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
        printf("LEMAH!\n");
    }
}

void printStack2(stack S)
{
    printf("Wishlist Makanan Manis:\n===================\n");
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
        printf("NDAK SEHAT!\n");
    }
}
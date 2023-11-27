// memanggil header
#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
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
// memasukan input ke list dengan addFirst
void addFirst(char judul[], char nama[], int nomor, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    // masukan ke kontainer
    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nomor = nomor;

    if ((*L).first == NULL) // biia null
    {
        baru->next = NULL; // akhir list
    }
    else // bila tidak null
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        // jika list tidak kosong
        // inisialisasi
        elemen *tunjuk = L.first;

        while (tunjuk != NULL)
        {
            // proses
            printf("%s", tunjuk->kontainer.judul);
            printf(" - %s\n", tunjuk->kontainer.nama);
            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    else
    {
        // proses jika list kosong
        printf("list kosong\n");
    }
}

// bubble secara asc
void bubjas(list *L)
{
    int i = 0;
    char judul[101];
    char nama[101];
    int nomor;
    // memanggil elemen di kontainer
    elemen *tunjuk1,
        *tunjuk2;
    while (i < countElement(*L)) // lalukan ingkremen sebanyak jumlah list
    {
        tunjuk1 = (*L).first;    // pointer ke first
        tunjuk2 = tunjuk1->next; // pointer ke next
        while (tunjuk2 != NULL)  // selama tidak null maka akan terus di inkremenkan
        {
            if (strcmp(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul) > 0) // penukaran secara bubble
            {
                strcpy(judul, tunjuk1->kontainer.judul);
                strcpy(nama, tunjuk1->kontainer.nama);
                nomor = tunjuk1->kontainer.nomor;

                strcpy(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul);
                strcpy(tunjuk1->kontainer.nama, tunjuk2->kontainer.nama);
                tunjuk1->kontainer.nomor = tunjuk2->kontainer.nomor;

                strcpy(tunjuk2->kontainer.judul, judul);
                strcpy(tunjuk2->kontainer.nama, nama);
                tunjuk2->kontainer.nomor = nomor;
            }
            // pengecekan ulang
            tunjuk1 = tunjuk2;
            tunjuk2 = tunjuk2->next;
        }
        i++; // ingkremenkan
    }
}

void bubjde(list *L)
{
    int i = 0;
    char judul[101];
    char nama[101];
    int nomor;
    // memanggil elemen di kontainer
    elemen *tunjuk1,
        *tunjuk2;
    while (i < countElement(*L)) // lalukan ingkremen sebanyak jumlah list
    {
        tunjuk1 = (*L).first;    // pointer ke first
        tunjuk2 = tunjuk1->next; // pointer ke next
        while (tunjuk2 != NULL)  // selama tidak null maka akan terus di inkremenkan
        {
            if (strcmp(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul) < 0) // penukaran secara bubble
            {
                strcpy(judul, tunjuk1->kontainer.judul);
                strcpy(nama, tunjuk1->kontainer.nama);
                nomor = tunjuk1->kontainer.nomor;

                strcpy(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul);
                strcpy(tunjuk1->kontainer.nama, tunjuk2->kontainer.nama);
                tunjuk1->kontainer.nomor = tunjuk2->kontainer.nomor;

                strcpy(tunjuk2->kontainer.judul, judul);
                strcpy(tunjuk2->kontainer.nama, nama);
                tunjuk2->kontainer.nomor = nomor;
            }
            // pengecekan ulang
            tunjuk1 = tunjuk2;
            tunjuk2 = tunjuk2->next;
        }
        i++; // ingkremenkan
    }
}

void bubnas(list *L)
{
    int i = 0;
    char judul[101];
    char nama[101];
    int nomor;
    // memanggil elemen di kontainer
    elemen *tunjuk1,
        *tunjuk2;
    while (i < countElement(*L)) // lalukan ingkremen sebanyak jumlah list
    {
        tunjuk1 = (*L).first;    // pointer ke first
        tunjuk2 = tunjuk1->next; // pointer ke next
        while (tunjuk2 != NULL)  // selama tidak null maka akan terus di inkremenkan
        {
            if (tunjuk1->kontainer.nomor > tunjuk2->kontainer.nomor) // penukaran secara bubble
            {
                strcpy(judul, tunjuk1->kontainer.judul);
                strcpy(nama, tunjuk1->kontainer.nama);
                nomor = tunjuk1->kontainer.nomor;

                strcpy(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul);
                strcpy(tunjuk1->kontainer.nama, tunjuk2->kontainer.nama);
                tunjuk1->kontainer.nomor = tunjuk2->kontainer.nomor;

                strcpy(tunjuk2->kontainer.judul, judul);
                strcpy(tunjuk2->kontainer.nama, nama);
                tunjuk2->kontainer.nomor = nomor;
            }
            // pengecekan ulang
            tunjuk1 = tunjuk2;
            tunjuk2 = tunjuk2->next;
        }
        i++; // ingkremenkan
    }
}

void bubnde(list *L)
{
    int i = 0;
    char judul[101];
    char nama[101];
    int nomor;
    // memanggil elemen di kontainer
    elemen *tunjuk1,
        *tunjuk2;
    while (i < countElement(*L)) // lalukan ingkremen sebanyak jumlah list
    {
        tunjuk1 = (*L).first;    // pointer ke first
        tunjuk2 = tunjuk1->next; // pointer ke next
        while (tunjuk2 != NULL)  // selama tidak null maka akan terus di inkremenkan
        {
            if (tunjuk1->kontainer.nomor < tunjuk2->kontainer.nomor) // penukaran secara bubble
            {
                strcpy(judul, tunjuk1->kontainer.judul);
                strcpy(nama, tunjuk1->kontainer.nama);
                nomor = tunjuk1->kontainer.nomor;

                strcpy(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul);
                strcpy(tunjuk1->kontainer.nama, tunjuk2->kontainer.nama);
                tunjuk1->kontainer.nomor = tunjuk2->kontainer.nomor;

                strcpy(tunjuk2->kontainer.judul, judul);
                strcpy(tunjuk2->kontainer.nama, nama);
                tunjuk2->kontainer.nomor = nomor;
            }
            // pengecekan ulang
            tunjuk1 = tunjuk2;
            tunjuk2 = tunjuk2->next;
        }
        i++; // ingkremenkan
    }
}
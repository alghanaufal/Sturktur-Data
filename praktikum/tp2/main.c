// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal TP 2
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */

#include "header.h"

int main()
{
    char nama[250];
    int tgl;
    char kode[250];
    list L;
    createList(&L);

    scanf("%s", nama);                 // masukan input
    if (strcmp(nama, "--stop--") != 0) // cek bila "--stop--" mmaka hentikan input
    {
        scanf("%d %s", &tgl, kode); // bila tidak sama masukan
        addFirst(nama, tgl, kode, &L);
        // addLast(nama, tgl, kode, &L);
        while (strcmp(nama, "--stop--") != 0) // bila blm ada "--stop--" maka terus ingkremenkan sampai menemukan "--stop--"
        {
            scanf("%s", nama);
            if (strcmp(nama, "--stop--") != 0)
            {
                scanf("%d %s", &tgl, kode);
                addFirst(nama, tgl, kode, &L);
                // addLast(nama, tgl, kode, &L);
            }
        }
    }
    printf("asc\n");
    printElement(L);
    printf("=====================\n");

    // printf("asc dell\n");
    // printElement(L);
    // printf("=====================\n");

    printf("desc\n");
    printElement_Reverse(L);
    printf("=====================\n");
    printf("=====================\n");

    // printDell(L);
    insertionasc(&L);
    select(&L);
    // printElement_Reverse(L);
    // printf("==== List Barang ====\n");
    // insertiondesc(&L);
    // printElement(L);
    // printf("=====================\n");

    return 0;
}
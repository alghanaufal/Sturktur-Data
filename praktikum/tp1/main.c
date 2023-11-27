// memanggil header
#include "header.h"

// kode utama
int main()
{
    int n = 0;       // ingkremen input
    char judul[101]; // var judul
    char nama[101];  // var nama
    int nomor;       // var nomor
    char tentu[50];  // var menentukan judul atau nomor
    char urut[10];   // var cara mengurutkannya secara asc atau desc
    list L;          // var list
    createList(&L);  // buat list

    scanf("%s", judul);          // masukan input
    if (strcmp(judul, "-") != 0) // cek bila "-" mmaka hentikan input
    {
        scanf("%s %d", nama, &nomor); // bila tidak sama masukan
        addFirst(judul, nama, nomor, &L);
        while (strcmp(judul, "-") != 0) // bila blm ada "-" maka terus ingkremenkan sampai menemukan "-"
        {
            n++; // ingkremenkan
            scanf("%s", judul);
            if (strcmp(judul, "-") != 0)
            {
                scanf("%s %d", nama, &nomor);
                addFirst(judul, nama, nomor, &L);
            }
        }
    }

    scanf("%s", tentu); // berikan input shorting secara judul atau nomor
    scanf("%s", urut);  // berikan input di shorting secara asc atau desc

    if (strcmp(tentu, "judul") == 0) // bila judul
    {
        if (strcmp(urut, "asc") == 0) // dan asc
        {
            bubjas(&L); // masuk ke prosedur
        }
        else if (strcmp(urut, "desc") == 0) // dan desc
        {
            bubjde(&L); // masuk ke propsedur
        }
    }
    else if (strcmp(tentu, "nomor") == 0) // bila nomor
    {
        if (strcmp(urut, "asc") == 0) // dan asc
        {
            bubnas(&L); // masuk ke prosedur
        }
        else if (strcmp(urut, "desc") == 0) // dan desc
        {
            bubnde(&L); // masuk ke prosedur
        }
    }

    printElement(L); // print hasil

    return 0; // akhir program
}
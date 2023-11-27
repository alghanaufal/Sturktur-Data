// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal UTS
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include "header.h"

void createList(list *L)
{

    (*L).first = NULL;
}

int countElementB(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        /*list tidak kosong*/
        eBaris *bantu;
        /*inisialisasi*/
        bantu = L.first;
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L)
{
    int hasil = 0;
    if (L.col != NULL)
    {
        /*list tidak kosong*/
        eKolom *bantu;
        /*inisialisasi*/
        bantu = L.col;
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(char kodep[], char namap[], list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));

    strcpy(baru->kontainer.kodep, kodep);
    strcpy(baru->kontainer.namap, namap);

    baru->col = NULL;
    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char kodeb[], char brg[], int bln, int thn, char jenis[], eBaris *L)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));

    strcpy(baru->kontainer_kol.kodeb, kodeb);
    strcpy(baru->kontainer_kol.brg, brg);
    baru->kontainer_kol.bln = bln;
    baru->kontainer_kol.thn = thn;
    strcpy(baru->kontainer_kol.jenis, jenis);

    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris *prev, char kodep[], char namap[])
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));

    strcpy(baru->kontainer.kodep, kodep);
    strcpy(baru->kontainer.namap, namap);
    baru->col = NULL;

    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom *prev, char kodeb[], char brg[], int bln, int thn, char jenis[])
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));

    strcpy(baru->kontainer_kol.kodeb, kodeb);
    strcpy(baru->kontainer_kol.brg, brg);
    baru->kontainer_kol.bln = bln;
    baru->kontainer_kol.thn = thn;
    strcpy(baru->kontainer_kol.jenis, jenis);

    if (prev->next_kol == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char kode[], char nama[], list *L)
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirstB(kode, nama, L);
    }
    else
    {
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eBaris *last = (*L).first;
        while (last->next != NULL)
        {
            /*iterasi*/
            last = last->next;
        }
        addAfterB(last, kode, nama);
    }
}

void addLastK(char kodeb[], char brg[], int bln, int thn, char jenis[], eBaris *L)
{
    if ((*L).col == NULL)
    {
        /*jika list adalah list kosong*/
        addFirstK(kodeb, brg, bln, thn, jenis, L);
    }
    else
    {
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eKolom *last = (*L).col;
        while (last->next_kol != NULL)
        {
            /*iterasi*/
            last = last->next_kol;
        }
        addAfterK(last, kodeb, brg, bln, thn, jenis);
    }
}

void delFirstK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /*jika list bukan list kosong*/
        eKolom *hapus = (*L).col;
        if (countElementK(*L) == 1)
        {
            (*L).col = NULL;
        }
        else
        {
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delAfterK(eKolom *prev)
{
    eKolom *hapus = prev->next_kol;
    if (hapus != NULL)
    {
        if (hapus->next_kol == NULL)
        {
            prev->next_kol = NULL;
        }
        else
        {
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delLastK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementK(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstK(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eKolom *last = (*L).col;
            eKolom *before_last;

            while (last->next_kol != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L)
{
    if (countElementK(*L) != 0)
    {
        int i;
        for (i = countElementK(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastK(L);
        }
    }
}

void delFirstB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        eBaris *hapus = (*L).first;
        if (hapus->col != NULL)
        {
            // menghapus semua elemen kolom jika ada
            delAllK(hapus);
        }
        if (countElementB(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("list kosong");
    }
}

void delAfterB(eBaris *prev)
{
    if (prev != NULL)
    {
        eBaris *hapus = prev->next;
        if (hapus != NULL)
        {
            if (hapus->col != NULL)
            {
                // menghapus semua elemen kolom jika ada
                delAllK(hapus);
            }
            if (hapus->next == NULL)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementB(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstB(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eBaris *last = (*L).first;
            eBaris *before_last;
            while (last->next != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(list *L)
{
    if (countElementB(*L) != 0)
    {
        int i;
        for (i = countElementB(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastB(L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris *bantu = L.first;
        while (bantu != NULL)
        {
            /*proses*/
            printf("%s", bantu->kontainer.kodep);
            printf(" %s\n", bantu->kontainer.namap);
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                printf("-%s %s %d %d %s\n", eCol->kontainer_kol.kodeb, eCol->kontainer_kol.brg, eCol->kontainer_kol.bln, eCol->kontainer_kol.thn, eCol->kontainer_kol.jenis);
                eCol = eCol->next_kol;
            }
            /*iterasi*/
            bantu = bantu->next;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

void tentu(int blnO, int thnO, eBaris *find, list L)
{
    list Lo;
    createList(&Lo);
    addFirstB("org", "OrganisasiBerwenang", &Lo);
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris *bantu = L.first;
        while (bantu != NULL)
        {
            /*proses*/
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                if ((eCol->kontainer_kol.bln >= blnO) && (eCol->kontainer_kol.thn >= thnO) && (strcpy(eCol->kontainer_kol.jenis, "sirup") == 0))
                {
                    printf("-%s %s %d %d %s\n", eCol->kontainer_kol.kodeb, eCol->kontainer_kol.brg, eCol->kontainer_kol.bln, eCol->kontainer_kol.thn, eCol->kontainer_kol.jenis);
                    addLastK(eCol->kontainer_kol.kodeb, eCol->kontainer_kol.brg, eCol->kontainer_kol.bln, eCol->kontainer_kol.thn, eCol->kontainer_kol.jenis, Lo.first);
                }
                eCol = eCol->next_kol;
            }
            /*iterasi*/
            bantu = bantu->next;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
    printElement(Lo);
}
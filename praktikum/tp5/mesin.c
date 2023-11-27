#include "header.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addSimpul(char c, graph *G) // add last
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;

    if ((*G).first == NULL)
    {
        /*jika graf kosong*/
        (*G).first = baru;
    }
    else
    {
        /*menambahkan simpul baru pada akhir graph*/
        simpul *last = (*G).first;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan, int beban)
{
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    baru->kontainer_jalur = beban;
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;

    if (awal->arc == NULL)
    {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else
    {
        /*menambahkan jalur baru pada akhir list jalur*/
        jalur *last = awal->arc;

        while (last->next_jalur != NULL)
        {
            last = last->next_jalur;
        }

        last->next_jalur = baru;
    }
}

simpul *findSimpul(char c, graph G)
{
    simpul *hasil = NULL;
    simpul *bantu = G.first;

    int ketemu = 0;
    while ((bantu != NULL) && (ketemu == 0))
    {
        if (bantu->kontainer == c)
        {
            hasil = bantu;
            ketemu = 1;
        }
        else
        {
            bantu = bantu->next;
        }
    }

    return hasil;
}

// prosedur bantu techi cari ibu
void findTechi(int visited[], int i, int n, char y, char path[], simpul *x, graph G)
{
    int k = n;                           // set k nya sama dengan n saat ini
    visited[x->kontainer - 'A' - 1] = 1; // set bahwa node kontainer saat ini sudah dikunjungi
    path[i] = x->kontainer;              // masukan array dengan kontainer saat ini
    i++;                                 // ingkremenkan untuk menambah jumlah jalurnya

    if (x->kontainer == y) // jika kontainernya sama dengan lokasi node ibu
    {
        simpan(path, i, n); // masuk ke prosedur print
    }
    else // jika tidak sama
    {
        jalur *bantu_jalur = x->arc; // buar var buat_jalur yg sama dengan x-arc
        while (bantu_jalur != NULL)  // selama bantu_jalurnya tidak NULL maka akan di looping
        {
            int j = bantu_jalur->kontainer_jalur;                       // buat var j untuk menampung beban jalur saat ini
            if (visited[bantu_jalur->tujuan->kontainer - 'A' - 1] == 0) // jika nodenya blm pernah di kunjungi
            {
                n = k + j;                                                    // jumlahkan kondisi n saat ini dengan kondisi beban saat ini
                simpul *temp = findSimpul(bantu_jalur->tujuan->kontainer, G); // cari node saat ini dan simpan di var temp
                findTechi(visited, i, n, y, path, temp, G);                   // masukan ke rekursive
            }
            bantu_jalur = bantu_jalur->next_jalur; // ingkremenkan bantu_jalur
        }
    }
    i--;                                 // kurangkan jumlah jalurnya
    visited[x->kontainer - 'A' - 1] = 0; // dan set ke 0
}

// presedur print
void simpan(char path[], int count, int n)
{
    for (int i = 0; i < count; i++) // lakukan looping sebanyak jumlah count
    {
        printf("%c ", path[i]); // lakukan print
    }
    printf("%d", n); // print jumlah bebannya
    printf("\n");    // newline
}
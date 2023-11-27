#include "header.h"

int main()
{
    graph G;       // var graph
    simpul *begin; // var node awal
    simpul *end;   // var node akhir

    createEmpty(&G); // buat graph

    char path[256];  // var array untuk menyimpan node yg nanti akan di print
    char x, y;       // var input node
    int visited[26], // var array untuk menentukan node yg sudah di kunjungi
        z,           // var input beban node
        n;           // var penentu banyaknya inputan

    scanf("%d", &n); // tentukan perapa banyak jumlah inputan
    // lakukan looping sebanyak jumlah n
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %c %d", &x, &y, &z); // masukan input
        // tambahkan node
        addSimpul(x, &G);
        addSimpul(y, &G);

        // cari node yg berhubungan
        begin = findSimpul(x, G); // awal node
        end = findSimpul(y, G);   // tujuan nodenya

        if ((begin != NULL) && (end != NULL)) // bila keduanya tidak NULL makan akan di tambahkan
        {
            addJalur(begin, end, z); // tambahkan jalurnya
        }
    }

    scanf(" %c %c", &x, &y); // inputkan keberadaan techi dengan ibunya
    // lakukan looping sebanyak jumlah huruf yang berguna untuk nanti menentukan node sudah di kunjungi atau blm
    for (int i = 0; i < 26; i++)
    {
        visited[i] = 0; // set ke 0 menandai kalau blm pernah dikunjungi
    }

    simpul *temp = findSimpul(x, G);            // cari posisi techi
    findTechi(visited, 0, 0, y, path, temp, G); // masuk ke prosedur cari ibu techi

    return 0;
}
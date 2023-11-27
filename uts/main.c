// /*
// Saya Alghaniyu Naufal Hamid NIM 2105673 mengerjakan soal UTS
// dalam mata kuliah Struktur Data untuk keberkahanNya maka
// saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
// */
#include "header.h"

int main()
{
    int n1 = 0;
    scanf("%d", &n1);

    char kodep[21],
        namap[51];

    char kodeb[21],
        brg[51],
        jenis[21];
    int bln,
        thn;

    int blnO,
        thnO;

    eBaris *find;
    list L;
    createList(&L);

    for (int i = 1; i <= n1; i++)
    {
        scanf("%s %s", &kodep, &namap);
        addLastB(kodep, namap, &L);

        if (i == 1)
        {
            find = L.first;
        }
        else
        {
            find = find->next;
        }

        int n2 = 0;
        scanf("%d", &n2);
        for (int j = 0; j < n2; j++)
        {
            scanf("%s %s %d %d %s", &kodeb, &brg, &bln, &thn, &jenis);
            addLastK(kodeb, brg, bln, thn, jenis, L.first);
            // addLastK(kodeb, brg, bln, thn, jenis, find);
        }

        if (i == 0)
        {
            i = n1;
        }
    }

    scanf("%d %d", &blnO, &thnO);

    // addLastB("org", "OrganisasiBerwenang", &L);
    // find = find->next;
    printElement(L);
    tentu(blnO, thnO, find, L);

    // printElement(Lo);

    return 0;
}
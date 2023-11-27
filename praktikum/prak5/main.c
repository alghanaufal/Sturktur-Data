#include "header.h"

int main()
{
    char kode[11];
    char nama[51];
    char brg[51];
    eBaris *find;
    list L;
    createList(&L);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%s %s", &nama, &kode);
        addLastB(nama, kode, &L);
        if (i == 1)
        {
            find = L.first;
        }
        else
        {
            find = find->next;
        }

        scanf("%s", &brg);
        addFirstK(brg, find);

        scanf("%s", &brg);
        addLastK(brg, find);

        scanf("%s", &brg);
        addAfterK(find->col->next_kol, brg);

        scanf("%s", &brg);
        addFirstK(brg, find);
        if (i == 0)
        {
            i = n;
        }
    }

    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);
    delAllB(&L);
    printElement(L);

    return 0;
}
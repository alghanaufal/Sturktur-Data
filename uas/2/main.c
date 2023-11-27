#include "header.h"

int main()
{
    graph G;
    simpul *begin;
    simpul *end;
    int count = 0;
    char arr1,
        arr2,
        x,
        y;

    scanf("%d", &count);

    createEmpty(&G);
    for (int i = 0; i < count; i++)
    {
        scanf(" %c", &arr1);
        scanf(" %c", &arr2);

        addSimpul(arr1, &G);
        addSimpul(arr2, &G);

        begin = findSimpul(arr1, G);
        end = findSimpul(arr2, G);

        if ((begin != NULL) && (end != NULL))
        {
            addJalur(begin, end);
        }
    }
    scanf(" %c", &x);
    scanf(" %c", &y);

    printGraph(G);
    printf("\n==============\n");

    cekGraph(G, G.first);
    findTechi(G, x, y);
    printGraph(G);
    printf("\n==============\n");

    return 0;
}
#include "header.h"
int main()
{
    tree T;
    int i,
        n;
    char str[201];

    scanf("%d", &n);

    input data[n];

    for (i = 0; i < n; i++)
    {
        scanf("%s", &str);
        InInput(n, str, data, i);
    }

    int range;
    scanf("%d", &range);

    InTree(&T, data, n);
    spasi(T.root, 0);

    printTreePreOrder(T.root, 0, 0);
    findrange(T.root, range);

    char nama[n][201];
    for (i = 0; i < n; i++)
    {
        // strcpy(nama[i], data[i].nama);
        // InDell(T.root, nama[i]);
        InDell(T.root, data[i].nama);
    }
    printf("\n");
    printTreePreOrder(T.root, 0, 0);
}
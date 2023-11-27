#include "header.h"

int main()
{
    list L1, L2;
    createList(&L1);
    createList(&L2);

    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char temp1[250];
        char tempn1[250];
        char tempj1[250];
        scanf("%s %s %s", temp1, tempn1, tempj1);
        if (i < n / 2)
        {
            addLast(temp1, tempn1, tempj1, &L2);
        }
        else
        {
            addFirst(temp1, tempn1, tempj1, &L1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        char temp2[250];
        char tempn2[250];
        char tempj2[250];
        scanf("%s %s %s", temp2, tempn2, tempj2);
        if (i < n / 2)
        {
            addLast(temp2, tempn2, tempj2, &L2);
        }
        else
        {
            addFirst(temp2, tempn2, tempj2, &L1);
        }
    }

    printElement(L1);
    // printf("\n");
    printElement(L2);

    return 0;
}
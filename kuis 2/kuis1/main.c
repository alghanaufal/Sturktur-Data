#include "header.h"

int main()
{
    stack S;
    int n = 0;
    int x = 0;

    createEmpty(&S);

    scanf("%d", &n);
    char nama[101],
        kode[11],
        tempat1[101];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s", &nama, &kode, &tempat1);
        push(nama, kode, tempat1, &S);
    }

    scanf("%d", &x);

    stack I[x + 1];
    char tempat2[x][101];

    for (int j = 0; j < x; j++)
    {
        createEmpty(&I[j]);
        scanf("%s", &tempat2[j]);
    }
    popa(S, I, x, tempat2);

    for (int j = 0; j < x; j++)
    {
        printf("stack %s\n", tempat2[j]);
        printStack(I[j]);
    }

    return 0;
}
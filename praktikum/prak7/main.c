#include "header.h"

int main()
{
    char nama[51], nim[51];
    queue Q1;
    queue Q2;
    createEmpty(&Q1);
    createEmpty(&Q2);

    scanf("%s %s", &nama, &nim);
    add(nama, nim, &Q1);
    scanf("%s %s", &nama, &nim);
    add(nama, nim, &Q1);

    scanf("%s %s", &nama, &nim);
    priority(nama, nim, 2, &Q1);

    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q1);

    del(&Q1, &Q2);

    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q1);
    printf("******************\n");
    printf("Queue 2\n");
    printQueue(Q2);

    scanf("%s %s", &nama, &nim);
    priority(nama, nim, 1, &Q1);
    scanf("%s %s", &nama, &nim);
    priority(nama, nim, 99, &Q1);

    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q1);

    del(&Q1, &Q2);
    del(&Q1, &Q2);

    scanf("%s %s", &nama, &nim);
    add(nama, nim, &Q1);

    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q1);
    printf("******************\n");
    printf("Queue 2\n");
    printQueue(Q2);
    printf("******************\n");

    return 0;
}
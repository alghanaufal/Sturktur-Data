#include "header.h"

int max[201];

void makeTree(char nama[201], char ortu[201], int harga, int jml, char komponen[][201], tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->nama, nama);
    strcpy(node->ortu, ortu);
    node->harga = harga;
    node->jml = jml;
    for (int i = 0; i < jml; i++)
    {
        strcpy(node->komponen[i], komponen[i]);
    }
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}
void addchild(char nama[201], char ortu[201], int harga, int jml, char komponen[][201], simpul *root)
{
    if (root != NULL)
    {
        simpul *new;
        new = (simpul *)malloc(sizeof(simpul));
        strcpy(new->nama, nama);
        strcpy(new->ortu, ortu);
        new->harga = harga;
        new->jml = jml;
        for (int i = 0; i < jml; i++)
        {
            strcpy(new->komponen[i], komponen[i]);
        }
        new->child = NULL;
        if (root->child == NULL)
        {
            new->sibling = NULL;
            root->child = new;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                new->sibling = root->child;
                root->child->sibling = new;
            }
            else
            {
                simpul *last = root->child;
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                new->sibling = root->child;
                last->sibling = new;
            }
        }
    }
}
simpul *findsimpul(char c[201], simpul *root)
{
    simpul *result = NULL;
    if (root != NULL)
    {
        if (strcmp(root->nama, c) == 0)
        {
            result = root;
        }
        else
        {
            simpul *ptr = root->child;
            if (ptr != NULL)
            {
                if (ptr->sibling == NULL)
                {
                    if (strcmp(ptr->nama, c) == 0)
                    {
                        result = ptr;
                    }
                    else
                    {
                        result = findsimpul(c, ptr);
                    }
                }
                else
                {
                    int found = 0;
                    while ((ptr->sibling != root->child) && (found == 0))
                    {
                        if (strcmp(ptr->nama, c) == 0)
                        {
                            result = ptr;
                            found = 1;
                        }
                        else
                        {
                            result = findsimpul(c, ptr);
                            ptr = ptr->sibling;
                            if (result != NULL)
                            {
                                found = 1;
                            }
                        }
                    }
                    if (found == 0)
                    {
                        if (strcmp(ptr->nama, c) == 0)
                        {
                            result = ptr;
                        }
                        else
                        {
                            result = findsimpul(c, ptr);
                        }
                    }
                }
            }
        }
    }
    return result;
}
void printTreePreOrder(simpul *root, int n, int lvl)
{
    if (root != NULL)
    {
        if (lvl != 0)
        {
            printf("\n");
        }
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        printf("|%s - %d\n", root->nama, root->harga);
        for (int i = 0; i < root->jml; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf(" ");
            }
            printf(" - %s\n", root->komponen[i]);
        }
        n += max[lvl];
        lvl++;

        simpul *bantu = root->child;

        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                printTreePreOrder(bantu, n, lvl);
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, n, lvl);
                    bantu = bantu->sibling;
                }
                printTreePreOrder(bantu, n, lvl);
            }
        }
    }
}
void InInput(int banyak, char str[201], input data[], int n)
{
    char str1[201],
        str2[201],
        str3[201],
        str4[201];
    int jml = 0, harga = 0, tag = 0,
        i, i1 = 0, i2 = 0, i3 = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '#')
        {
            tag++;
            continue;
        }
        if (tag == 0)
        {
            str1[i] = str[i];
        }
        if (tag == 1)
        {
            str2[i1] = str[i];
            i1++;
        }
        if (tag == 2)
        {
            str3[i2] = str[i];
            i2++;
        }
        if (tag == 3)
        {
            str4[i3] = str[i];
            i3++;
        }
    }

    str1[i] = '\0';
    str2[i1] = '\0';
    str3[i2] = '\0';
    for (i = 0; i < strlen(str3); i++)
    {
        harga *= 10;
        harga += str3[i] - '0';
    }
    str4[i3] = '\0';
    for (i = 0; i < strlen(str4); i++)
    {
        jml *= 10;
        jml += str4[i] - '0';
    }

    strcpy(data[n].nama, str1);
    strcpy(data[n].ortu, str2);
    data[n].harga = harga;
    data[n].inputjml = jml;
    char komponen[jml][201];

    for (i = 0; i < jml; i++)
    {
        scanf("%s", komponen[i]);
        strcpy(data[n].komponen[i], komponen[i]);
    }
}

void InTree(tree *T, input data[], int banyak)
{
    for (int i = 0; i < banyak; i++)
    {
        if ((strcmp(data[i].ortu, "null") == 0) || strcmp(data[i].ortu, "NULL") == 0)
        {
            makeTree(data[i].nama, data[i].ortu, data[i].harga, data[i].inputjml, data[i].komponen, T);
        }
        else
        {
            simpul *node = findsimpul(data[i].ortu, (*T).root);
            if (node != NULL)
            {
                addchild(data[i].nama, data[i].ortu, data[i].harga, data[i].inputjml, data[i].komponen, node);
            }
        }
    }
}
void spasi(simpul *root, int len)
{
    int n = root->jml, i = 0;

    int coba,
        coba1 = 0,
        coba2;

    int test[n];

    if (root != NULL)
    {
        for (i = 0; i <= n; i++)
        {
            test[i] = strlen(root->komponen[i]) + 4;
            if (test[i] > coba1)
            {
                coba2 = test[i];
            }
            coba1 = test[i];
        }
        int j = 0;
        if (root->harga >= 1000)
        {
            j = 4;
        }
        else if (root->harga >= 100)
        {
            j = 3;
        }
        else if (root->harga >= 10)
        {
            j = 2;
        }
        else if (root->harga >= 1)
        {
            j = 1;
        }

        coba = strlen(root->nama) + j + 5;

        if (coba > max[len] || coba2 > max[len])
        {
            if (coba2 > max[len])
            {
                max[len] = coba2;
            }
            else if (coba > max[len])
            {
                max[len] = coba;
            }
        }

        len++;

        simpul *bantu = root->child;

        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                spasi(bantu, len);
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    spasi(bantu, len);
                    bantu = bantu->sibling;
                }
                spasi(bantu, len);
            }
        }
    }
}

void delAll(simpul *root)
{
    if (root != NULL)
    {
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {
                delAll(root->child);
            }
            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = root->child;
                while (bantu->sibling != root->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }
                // Tambahan
                delAll(bantu);
            }
            free(root);
        }
        else
        {
            free(root);
        }
    }
}

void delChild(char nama[201], simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {

                if (strcmp(root->child->nama, nama) == 0)
                {
                    delAll(root->child);
                    root->child = NULL;
                }
            }
            else
            {
                simpul *prev = NULL;

                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (strcmp(hapus->nama, nama) == 0)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                if ((ketemu == 0) && (strcmp(hapus->nama, nama) == 0))
                {
                    ketemu = 1;
                }

                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }

                    if (prev == NULL)
                    {
                        if ((hapus->sibling == last) &&
                            (last->sibling == root->child))
                        {

                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child) && (prev->sibling == last))
                        {
                            root->child->sibling = NULL;
                        }
                        else
                        {
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                }
            }
        }
    }
}

void findrange(simpul *node, int harga)
{
    if (node != NULL)
    {
        if (node->harga < harga)
        {
            node->harga = 0;
        }
        simpul *bantu = node->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                findrange(bantu, harga);
            }
            else
            {
                while (bantu->sibling != node->child)
                {
                    findrange(bantu, harga);
                    bantu = bantu->sibling;
                }

                findrange(bantu, harga);
            }
        }
    }
}

void InDell(simpul *node, char nama[201])
{
    simpul *test = findsimpul(nama, node);
    if (test != NULL)
    {
        if (test->harga == 0)
        {
            simpul *point = findsimpul(test->ortu, node);
            if (point != NULL)
            {
                delChild(test->nama, point);
            }
        }
    }
}
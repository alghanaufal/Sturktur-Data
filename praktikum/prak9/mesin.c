#include "header.h"

void makeTree(data input, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->kontainer.nama, input.nama);
    node->kontainer.nilai = input.nilai;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(data input, simpul *root)
{
    /* jika simpul root tidak kosong,
    berarti dapat ditambahkan simpul anak
    */
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    strcpy(baru->kontainer.nama, input.nama);
    baru->kontainer.nilai = input.nilai;
    baru->child = NULL;

    if (root->child == NULL)
    {
        /* jika simpul root belum
        memiliki simpul anak maka simpul baru
        menjadi anak pertama */

        baru->sibling = NULL;
        root->child = baru;
    }
    if (root->child->sibling == NULL)
    {
        /* jika simpul root memiliki
        anak yang belum memiliki saudara, maka
        simpul baru menjadi anak kedua */
        baru->sibling = root->child;
        root->child->sibling = baru;
    }
    else
    {
        simpul *last = root->child;
        /* mencari simpul anak terakhir
        karena akan dikaitkan dengan simpul
        baru sebagai simpul anak terakhir yang
        baru, simpul anak terakhir adalah yang
        memiliki sibling simpul anak pertama,
        maka selama belum sampai pada simpul
        anak terakhir, penunjuk last akan
        berjalan ke simpul anak berikutnya */
        while (last->sibling != root->child)
        {
            last = last->sibling;
        }
        baru->sibling = root->child;
        last->sibling = baru;
    }
}

void delAll(simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong */
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */
                delAll(root->child);
                free(root);
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
            }
            free(root);
        }
        else
        {
            free(root);
        }
    }
}

void delChild(char nama[], int nilai, simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                if ((strcmp(root->child->kontainer.nama, nama) == 0) && (root->child->kontainer.nilai == nilai))
                {
                    delAll(root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("%s tidak ditemukan\n", nama);
                }
            }
            else
            {
                simpul *prev = NULL;
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if ((strcmp(hapus->kontainer.nama, nama) == 0) && (root->child->kontainer.nilai == nilai))
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                if ((ketemu == 0) && ((strcmp(hapus->kontainer.nama, nama) == 0) && (hapus->kontainer.nilai == nilai)))
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
                        if ((hapus->sibling == last) && (last->sibling == root->child))
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
                        if ((prev == root->child) && (last->sibling == root->child))
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
                else
                {
                    printf("%s tidak ditemukan\n", nama);
                }
            }
        }
    }
}

simpul *findSimpul(data input, simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer.nama, input.nama) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (strcmp(bantu->kontainer.nama, input.nama) == 0)
                    {
                        hasil = bantu;
                    }

                    else
                    {
                        hasil = findSimpul(input, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if (strcmp(bantu->kontainer.nama, input.nama) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(input, bantu);
                            bantu = bantu->sibling;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam
                    pengulangan*/
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer.nama, input.nama) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(input, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void printTreePreOrder(simpul *root)
{
    if (root != NULL)
    {
        printf("%s %d-", root->kontainer.nama, root->kontainer.nilai);
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/

                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu);
                    bantu = bantu->sibling;
                }

                /*memproses simpul anak
                terakhir karena belum terproses
                dalam pengulangan*/
                printTreePreOrder(bantu);
            }
        }
    }
}

void printTreePostOrder(simpul *root)
{

    if (root != NULL)
    {
        simpul *bantu = root->child;

        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePostOrder(bantu);
            }
            else
            {
                /*jika memiliki banyak simpul
                anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePostOrder(bantu);
                    bantu = bantu->sibling;
                }

                /*memproses simpul anak
                terakhir karena belum terproses
                dalam pengulangan*/

                printTreePostOrder(bantu);
            }
        }
        printf("%s %d-", root->kontainer.nama, root->kontainer.nilai);
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    { // jika simpul root1 tidak kosong
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        if (root1->sibling != NULL)
        { // jika root1 mempunyai sibling
            (*root2)->sibling = root1->sibling;
        }
        else
        { // jika root1 tidak mempunyai sibling
            (*root2)->sibling = NULL;
        }
        if (root1->child != NULL)
        { // jika root1 mempunyai anak
            (*root2)->child = root1->child;
        }
        else
        { // jika root1 tidak mempunyai anak
            (*root2)->child = NULL;
        }

        if (root1->child != NULL)
        { // jika root1 memiliki anak
            if (root1->child->sibling == NULL)
            { // jika memiliki satu simpul anak
                copyTree(root1->child, &(*root2)->child);
            }
            else
            { // jika memiliki banyak simpul anak
                simpul *ptr1 = root1->child;
                simpul *ptr2 = (*root2)->child;
                while (ptr1->sibling != root1->child)
                {
                    copyTree(ptr1, &ptr2);
                    ptr1 = ptr1->sibling;
                    ptr2 = ptr2->sibling;
                }
                /* memproses simpul anak terakhir karena
                belum terproses dalam pengulangan */
                copyTree(ptr1, &ptr2);
            }
        }
    }
}

int isEqual(simpul *root1, simpul *root2)
{
    int hasil = 1;
    if ((root1 != NULL) && (root2 != NULL))
    {
        if (root1->kontainer.nama != root2->kontainer.nama)
        {
            hasil = 0;
        }
        else
        {
            if ((root1->child != NULL) && (root2->child != NULL))
            {
                if (root1->child->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    hasil = isEqual(root1->child, root2->child);
                }
                else
                {
                    /*jika memiliki banyak simpul
                    anak*/
                    simpul *bantu1 = root1->child;
                    simpul *bantu2 = root2->child;

                    while (bantu1->sibling != root1->child)
                    {
                        if ((bantu1 != NULL) && (bantu2 != NULL))
                        {
                            hasil = isEqual(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        }
                        else
                        {
                            hasil = 0;

                            break;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                    hasil = isEqual(bantu1, bantu2);
                }
            }
        }
    }
    else
    {
        if ((root1 != NULL) ||
            (root2 != NULL))
        {
            hasil = 0;
        }
    }
    return hasil;
}
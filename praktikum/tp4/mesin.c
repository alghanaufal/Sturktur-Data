// memanggil header
#include "header.h"

// buat pohon
void makeTree(char input[], tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->kontainer, input); // masukan ke kontainer
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

// tambah child
void addChild(char input[], simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak
        */
        simpul *new;
        new = (simpul *)malloc(sizeof(simpul));
        strcpy(new->kontainer, input); // masukan ke kontainer
        new->child = NULL;
        if (root->child == NULL)
        {
            /* jika simpul root belum
            memiliki simpul anak maka simpul baru
            menjadi anak pertama */
            new->sibling = NULL;
            root->child = new;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki
                anak yang belum memiliki saudara, maka
                simpul baru menjadi anak kedua */
                new->sibling = root->child;
                root->child->sibling = new;
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
                new->sibling = root->child;
                last->sibling = new;
            }
        }
    }
}

// prosedur hapus semua
void delAll(simpul *root)
{
    if (root != NULL) // jika simpul root tidak kosong
    {
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL) // jika hanya memiliki satu simpul anak
            {
                delAll(root->child);
            }
            else
            {
                simpul *point;
                simpul *process;
                point = root->child;
                while (point->sibling != root->child)
                {
                    process = point;
                    point = point->sibling;
                    delAll(process);
                }
                delAll(point);
            }
            free(root);
        }
        else
        {
            free(root);
        }
    }
}

// Prosedur hapus CHILD
void delChild(char nama[], simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL) // jika hanya mempunyai satu anak
            {
                if ((strcmp(root->child->kontainer, nama) == 0))
                {
                    delAll(root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("%s tidak ditemukan\n", nama);
                }
            }
            else // jika memiliki lebih dari satu simpul anak
            {
                simpul *prev = NULL;
                // mencari simpul yang akan dihapus
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if ((strcmp(hapus->kontainer, nama) == 0))
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                /*memproses simpul anak terakhir karena
                belum terproses dalam pengulangan*/
                if ((ketemu == 0) && ((strcmp(hapus->kontainer, nama) == 0)))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
                    membantu proses atau pemeriksaan jika yang
                    dihapus nantinya anak terakhir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL) // jika simpul yang dihapus anak pertama
                    {
                        if ((hapus->sibling == last) && (last->sibling == root->child)) // jika hanya ada 2 anak
                        {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else // juka ada lebih dari 2 anak
                        {
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child->sibling)) // jika ada 2 atau lebih anak yang di hapus di simpul
                        {
                            root->child->sibling = NULL;
                        }
                        else
                        {
                            /* jika yang dihapus bukan
                            simpul anak pertama dan simpul root
                            memiliki simpul anak lebih dari dua
                            simpul */
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

// proseedur mencari simpul
simpul *findSimpul(char nama[], simpul *root)
{
    simpul *result = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer, nama) == 0)
        {
            result = root;
        }
        else
        {
            simpul *point = root->child;
            if (point != NULL)
            {
                if (point->sibling == NULL) // jika hanya memiliki 1 simpul anak
                {
                    if (strcmp(point->kontainer, nama) == 0)
                    {
                        result = point;
                    }
                    else
                    {
                        result = findSimpul(nama, point);
                    }
                }
                else // jika memiliki banyak simpul anak
                {
                    int ketemu = 0;
                    while ((point->sibling != root->child) && (ketemu == 0))
                    {
                        if (strcmp(point->kontainer, nama) == 0)
                        {
                            result = point;
                            ketemu = 1;
                        }
                        else
                        {
                            result = findSimpul(nama, point);
                            point = point->sibling;
                            if (result != NULL)
                            {
                                ketemu = 1;
                            }
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam
                    pengulangan*/
                    if (ketemu == 0)
                    {
                        if (strcmp(point->kontainer, nama) == 0)
                        {
                            result = point;
                        }
                        else
                        {
                            result = findSimpul(nama, point);
                        }
                    }
                }
            }
        }
    }
    return result;
}

// proseedur print hasil secara pre order
void printTreePreOrder(simpul *root, int mark)
{
    if (root != NULL)
    {
        for (int i = 0; i < mark; i++) // lakukan looping untuk print panah
        {
            printf("->");
        }
        printf("%s\n", root->kontainer); // output
        simpul *point = root->child;
        if (point != NULL)
        {
            if (point->sibling == NULL) // jika memiliki 1 simpul anak
            {
                ++mark;                         // ingkremenkan
                printTreePreOrder(point, mark); // lakukan recursive
                --mark;                         // kurangkan kembali untuk mengembalikan nilai mark
            }
            else // jika memiliki banyak anak
            {
                while (point->sibling != root->child) // mencetak simpul anak
                {
                    ++mark;                         // ingkremenkan
                    printTreePreOrder(point, mark); // lakukan recursive
                    --mark;                         // kurangkan kembali untuk mengembalikan nilai mark
                    point = point->sibling;
                }
                /*memproses simpul anak
                terakhir karena belum terproses
                dalam pengulangan*/
                ++mark;                         // ingkremenkan
                printTreePreOrder(point, mark); // lakukan recursive
                --mark;                         // kurangkan kembali untuk mengembalikan nilai mark
            }
        }
    }
}

// prosedur hapus simicolon di akhir
void delSimicolon(char str[], int len)
{
    for (int i = 0; i < len; i++) // lakukan looping sebanyak jumlah string
    {
        if (i == len - 1) // bila nilai i menyentuh len - 1
        {
            str[i] = '\0'; // jadikan null
        }
    }
}
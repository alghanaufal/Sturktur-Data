#include "header.h"

int tampungOutput[100], Idx;

/* Membuat Tree Baru */
void makeTree(data c, tree *T)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

/* Menambah Simpul di Kanan Simpul yg Ditunjuk */
void addRight(int kiri, simpul *root)
{
    if (root->right == NULL)
    {
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul)); // meminta memori         // memasukkan isi simpul
        baru->kontainer.kiri = kiri;             // memasukkan isi simpul
        baru->right = NULL;                      // simpul kanan dikosongkan
        baru->left = NULL;                       // simpul kiri dikosongkan
        root->right = baru;                      // simpul baru dimasukkan ke simpul yg ditunjuk (root)
    }
    else
    {
        printf("sub pohon kanan telah terisi");
    }
    // if(kiri != 0) {
    //     printf("> %d %d\n", kiri, kanan);
    //     addLeft(kiri / 2, Kanan, root->right);
    //     printf("hey!\n");
    // }
    // if(kanan != 0) {
    //     addRight(Kiri, kanan / 2, root->right);
    // }
}

/* Menambah Simpul di Kiri Simpul yg Ditunjuk */
// alur sama seperti prosedur addRight() hanya berbeda di posisi simpul
void addLeft(int kiri, simpul *root)
{
    if (root->left == NULL)
    {
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer.kiri = kiri;
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    }
    else
    {
        printf("sub pohon kiri telah terisi");
    }
    // if(kiri != 0 && kanan != 0) {
    //     printf("> %d %d\n", kiri, kanan);
    //     addLeft(kiri / 2, Kanan, root->left);
    //     printf("hey!\n");
    // }
    // if(kanan != 0 && kanan != 0) {
    //     addRight(Kiri, kanan / 2, root->left);
    // }
    // if(kiri != 0 && kanan != 0) {
    //     printf("> %d %d\n", kiri, kanan);
    //     // addLeft(kiri / 2, kanan, root->left);
    //     addRight(kiri, kanan / 2, root->left);
    // }
}

/* Prosedur Menambahkan dan Mengenerate Data untuk Node / Simpul Anak */
void addData(int kiri, int kanan, simpul *root)
{
    // if (kiri != kiri * kanan)
    // {
    //     if (kiri % 2 == 0)
    //     {
    //         addRight(kiri / kanan, root->right);
    //     }
    //     else
    //     {
    //         addLeft(kiri / kanan, root->left);
    //     }
    // }
    // else
    // {
    if (kiri == kiri * kanan)
    {
        if (kiri % 2 == 0)
        {
            addRight(kiri / kanan, root->right);
        }
        else
        {
            addLeft(kiri / kanan, root->left);
        }
    }
    // }

    /*
    if (kiri / 4 != 0 && kanan / 4 != 0)
    {
        // jika data pada simpul masih bisa dibagi sekali lagi
        // masukkan data untuk simpul kiri
        addLeft(kiri / 2, kanan, root);
        addData(root->kontainer.kiri / 2, kanan, root->left);
        // masukkan data untuk simpul kanan
        addRight(kiri, kanan / 2, root);
        addData(root->kontainer.kiri, root->kontainer.kanan / 2, root->right);
    }
    else
    {
        // jika data hanya data dibagi sekali lagi
        if (kiri / 2 != 0 && kanan / 2 != 0)
        {
            // Mengenerate simpul sebelah kiri
            addLeft(kiri / 2, kanan, root);
            tampungOutput[Idx] = kiri / 2;
            tampungOutput[Idx + 1] = kanan;
            Idx += 2;
        }
        if (kanan / 2 != 0 && kiri / 2 != 0)
        {
            // Mengenerate simpul sebelak kanan
            addRight(kiri, kanan / 2, root);
            tampungOutput[Idx] = kiri;
            tampungOutput[Idx + 1] = kanan / 2;
            Idx += 2;
        }
    }*/
}

/* Menghapus Seluruh Simpul Tree */
void delAll(simpul *root)
{
    if (root != NULL)
    {
        // dipanggil rekursif
        // dihapus dari paling kiri bawah
        delAll(root->left);
        delAll(root->right);
        free(root); // membebaskan memori root
    }
}

/* Menghapus Simpul di Kanan */
void delRight(simpul *root)
{
    if (root != NULL)
    {
        // jika root (simpul yg ditunjuk) tidak kosong
        if (root->right != NULL)
        {
            // jika ada simpul kanannya
            delAll(root->right); // hapus bersama childnya
            root->right = NULL;
        }
    }
}

/* Menghapus Simpul di Kiri */
// sama seperti prosedur delRight() hanya berbeda di posisi simpul
void delLeft(simpul *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

/* Mencetak Isi Simpul dari Atas Kiri ke Bawah */
void printTreePreOrder(simpul *root, simpul *almtRoot)
{
    if (root != NULL)
    {
        // jika simpul yg ditunjuk (root) tidak kosong
        if (root == almtRoot)
        {
            // jika simpul yg ditunjuk adalah root utama
            printf("%c", root->kontainer);
        }
        else
        {
            // jika simpul yg ditunjuk bukan root utama
            printf(" - %c", root->kontainer);
        }
        // rekursif, kiri dulu
        printTreePreOrder(root->left, almtRoot);
        // baru kanan kalau kiri NULL
        printTreePreOrder(root->right, almtRoot);
    }
}

/* Mencetak Isi Simpul Kiri lalu Kanan */
void printTreeInOrder(simpul *root)
{
    if (root != NULL)
    {
        // rekursif, kiri dulu
        printTreeInOrder(root->left);
        if (root->left != NULL)
        {
            // jika kirinya ada
            printf(" - ");
        }
        printf("%c", root->kontainer);
        if (root->right != NULL)
        {
            // jika kanannya ada
            printf(" - ");
        }
        // rekursif, simpul yg kanan
        printTreeInOrder(root->right);
    }
}

/* Mencetak Isi Simpul dari Kanan Bawah ke Kiri */
void printTreePostOrder(simpul *root, simpul *almtRoot)
{
    if (root != NULL)
    {
        // rekursif, kiri dulu
        printTreePostOrder(root->left, almtRoot);
        // kalau kiri NULL, pindah ke kanan
        printTreePostOrder(root->right, almtRoot);
        printf("%d * %d", root->kontainer.kiri, root->kontainer.kanan);
        if (root != almtRoot)
        {
            // jika bukan elemen root utama
            printf(" \n ");
        }
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        printf("root : %c\n", root1->kontainer);
        if (root1->left != NULL)
        {
            printf("< %c\n", root1->left->kontainer);
            copyTree(root1->left, &(*root2)->left);
        }
        if (root1->right != NULL)
        {
            printf("> %c\n", root1->right->kontainer);
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

// int isEqual(simpul *root1, simpul *root2) {
//     int hasil = 1;
//     if((root1 != NULL) && (root2 != NULL)) {
//         if(root1->kontainer != root2->kontainer) {
//             hasil = 0;
//         } else {
//             hasil = isEqual(root1->left, root2->left);
//             hasil = isEqual(root1->right, root2->right);
//         }
//     } else {
//         if((root1 != NULL) || (root2 != NULL)) {
//             hasil = 0;
//         }
//     }
//     return hasil;
// }
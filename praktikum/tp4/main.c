// memanggil header
#include "header.h"

int main()
{
    tree T;         // var pohon
    simpul *find;   // var simpul
    char str1[256], // var str
        str2[256],
        str3[256];
    int n = 0,    // var tentukan jumlah output
        mark = 0; // var marker

    do // lakukan 1 perintah terlebih dahulu
    {
        scanf("%s", str1);              // masukan query string
        if (strcmp(str1, "DONE;") != 0) // bila DONE; maka program selesai
        {
            if (strcmp(str1, "CHILD") == 0) // bila query CHILD
            {                               // Berikan input
                scanf("%s", str2);
                scanf("%s", str3);
                delSimicolon(str3, strlen(str3)); // delete ;
                find = findSimpul(str3, T.root);  // cari node
                addChild(str2, find);             // tambahkan child
            }
            else if (strcmp(str1, "PREORDER;") == 0) // bila query PRINTORDER
            {
                n++;
                printf("Output %d:\n=========\n", n);
                printTreePreOrder(T.root, mark); // masuk ke prosedur print
            }
            else if (strcmp(str1, "DELLCHILD") == 0) // bila query DELLCHILD
            {                                        // Berikan input
                scanf("%s", str2);
                scanf("%s", str3);
                delSimicolon(str3, strlen(str3)); // delete ;
                find = findSimpul(str3, T.root);  // cari node
                delChild(str2, find);             // masukan untuk di hapus
            }
            else
            { // Berikan input
                scanf("%s", str2);
                delSimicolon(str2, strlen(str2)); // delete ;
                makeTree(str2, &T);               // buat pohon
            }
        }
    } while (strcmp(str1, "DONE;") != 0); // selesaikan looping bila query DONE;
    printf("=========\n");

    return 0;
}
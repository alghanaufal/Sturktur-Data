#include "header.h"

int main()
{
    tree T;
    makeTree('A', &T);
    addLeft('B', T.root);
    addRight('C', T.root);
    // tentukan posisinya -> tentukan pohon
    addLeft('D', T.root->left);
    addRight('E', T.root->left);
    addLeft('F', T.root->right);
    addRight('G', T.root->right);
    addLeft('H', T.root->right->right);

    printf("=================\n");

    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");

    printf("inOrder\n");
    printTreeInOrder(T.root);
    printf("\n=================\n");

    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n=================\n");

    printf("levelOrder\n");
    for (int i = 1; i <= heightTree(T.root); i++)
    {
        printTreeLevelOrder(T.root, i);
    }
    printf("\n=================\n");

    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("pohon sama\n");
    }
    else
    {
        printf("pohon tidak sama\n");
    }

    // tentukan posisinya -> tentukan pohon
    delLeft(T.root->left);
    delRight(T.root->left);

    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");

    return 0;
}
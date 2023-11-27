#include "header.h"

int main()
{
    tree T;

    char in[15];
    for (int i = 0; i < 14; i++)
    {
        scanf(" %c", &in[i]);
    }

    makeTree(in[0], &T);
    addLeft(in[1], T.root);
    addRight(in[2], T.root);
    // tentukan posisinya -> tentukan pohon
    addLeft(in[3], T.root->right);
    addRight(in[4], T.root->left);
    addRight(in[5], T.root->right);
    addLeft(in[6], T.root->left->right);
    addRight(in[7], T.root->right->left);
    addRight(in[8], T.root->left->right);
    addRight(in[9], T.root->right->right);
    addLeft(in[10], T.root->right->right);
    addLeft(in[11], T.root->left->right->left);
    addLeft(in[12], T.root->right->left->right);
    addRight(in[13], T.root->right->left->right);

    printf("Pre Order:\n");
    printTreePreOrder(T.root);

    delLeft(T.root->left->right->left);
    printf("\nIn Order:\n");
    printTreeInOrder(T.root);

    delRight(T.root->right->right);
    printf("\nPost Order:\n");
    printTreePostOrder(T.root);
    printf("\n");

    // printf("levelOrder\n");
    // for (int i = 1; i <= heightTree(T.root); i++)
    // {
    //     printTreeLevelOrder(T.root, i);
    // }
    // printf("\n=================\n");

    // tree T2;
    // copyTree(T.root, &T2.root);
    // if (isEqual(T.root, T2.root) == 1)
    // {
    //     printf("pohon sama\n");
    // }
    // else
    // {
    //     printf("pohon tidak sama\n");
    // }

    // tentukan posisinya -> tentukan pohon

    return 0;
}
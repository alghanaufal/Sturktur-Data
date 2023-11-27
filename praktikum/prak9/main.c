#include "header.h"

int main()
{
    data input[21];
    for (int i = 0; i < 9; i++)
    {
        scanf("%s %d", &input[i].nama, &input[i].nilai);
    }
    scanf("%s", &input[10].nama);

    tree T;
    makeTree(input[0], &T);
    addChild(input[1], T.root);
    addChild(input[2], T.root);
    addChild(input[3], T.root);
    addChild(input[4], T.root->child);
    addChild(input[5], T.root->child);
    printf("=================\n");
    printTreePreOrder(T.root);
    printf("\n");
    printTreePostOrder(T.root);
    printf("\n");

    delChild(T.root->child->child->sibling->kontainer.nama, T.root->child->child->sibling->kontainer.nilai, T.root->child);

    printTreePreOrder(T.root);
    printf("\n");
    printTreePostOrder(T.root);
    printf("\n");

    addChild(input[3], T.root->child->sibling);
    addChild(input[4], T.root->child->sibling);
    addChild(input[5], T.root->child->sibling->sibling);

    printTreePreOrder(T.root);
    printf("\n");

    return 0;
}
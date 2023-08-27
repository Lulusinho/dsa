#include "binary_tree.h"

int main(int argc, char **argv)
{
    bin_t *tree = NULL;
    tree = bin_insert(tree, 10);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 20);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 30);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 18);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 5);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 0);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 2);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 1);
    preorder(tree);
    printf("\n");
    tree = bin_insert(tree, 100);
    preorder(tree);
    printf("\n");

    bin_t *search = bin_search(tree, 0);

    tree = bin_delete(tree, 100);
    preorder(tree);
    printf("\n");
    tree = bin_delete(tree, 0);
    preorder(tree);
    printf("\n");
    tree = bin_delete(tree, 10);
    preorder(tree);
    printf("\n");

    printf("%d", MOD(20));

    return 0;
}
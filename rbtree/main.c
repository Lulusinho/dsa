#include "redblack.h"
int main(int argc, char **argv)
{
    rb_t *tree = NULL;
    tree = rb_insert(tree, 10);
    preorder(tree);
    printf("\n");
    tree = rb_insert(tree, 30);
    preorder(tree);
    printf("\n");
    tree = rb_insert(tree, 5);
    preorder(tree);
    printf("\n");
    tree = rb_insert(tree, 15);
    preorder(tree);
    printf("\n");
    tree = rb_insert(tree, 60);
    preorder(tree);
    printf("\n");
    tree = rb_insert(tree, 70);
    preorder(tree);
    printf("\n");
    tree = rb_insert(tree, 1);
    preorder(tree);
    printf("\n");
    tree = rb_insert(tree, 6);
    preorder(tree);
    printf("\n");

    printf("%d", get_color(tree));

    return 0;
}
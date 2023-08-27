#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) (a < 0 ? a * (-1) : a)

typedef struct binary_tree
{
    int key;
    struct binary_tree *left;
    struct binary_tree *right;
} bin_t;


bin_t *bin_min(bin_t *);
bin_t *bin_max(bin_t *);

void preorder(bin_t *);
void order(bin_t *);
void postorder(bin_t *);

bin_t *bin_newnode(int key);
bin_t *bin_search(bin_t *, int);
bin_t *bin_insert(bin_t *, int);
bin_t *bin_delete(bin_t *, int);

int bin_height(bin_t *);
int bin_depth(bin_t *);
int bin_width(bin_t *);

#endif

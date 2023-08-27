#ifndef __AVL_H__
#define __AVL_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) (a < 0 ? a * (-1) : a)

typedef struct avl_tree
{
    int key;
    int height;
    struct avl_tree *left;
    struct avl_tree *right;

} avl_t;

int calculatefb(avl_t *);
avl_t *LL(avl_t *);
avl_t *RR(avl_t *);

avl_t *newnode(int);
avl_t *avl_insert(avl_t *, int key);
avl_t *avl_delete(avl_t *, int); // falta implementar
avl_t *avl_search(avl_t *, int);

void preorder(avl_t *);
void order(avl_t *);
void postorder(avl_t *);

avl_t *avl_min(avl_t *);
avl_t *av_lmax(avl_t *);
int avl_height(avl_t *);

int avl_depth(avl_t *);
int avl_width(avl_t *);

#endif
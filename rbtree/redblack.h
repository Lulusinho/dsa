#ifndef __REDBLACK_H__
#define __REDBLACK_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)

#define BLACK 0
#define RED 1

typedef struct rb
{
    int key;
    int color;
    struct rb *left;
    struct rb *right;
    struct rb *parent;
} rb_t;

//Rotation functions
rb_t *RR(rb_t *);
rb_t *LL(rb_t *);

//Red-black specifc functions
rb_t *get_grandparent(rb_t *root);
rb_t *get_uncle(rb_t *root);

//Core tree operations
rb_t *newnode(int);
rb_t *rb_insert(rb_t *, int);

//general tree operations
void preorder(rb_t *);

#endif
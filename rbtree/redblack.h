#ifndef __REDBLACK_H__
#define __REDBLACK_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)

#define BLACK 0
#define RED 1

//tree struct
typedef struct rb
{
    int key;
    int color;
    struct rb *left;
    struct rb *right;
    struct rb *parent;
} rb_t;
rb_t Tnill;

// Rotation functions
rb_t *RR(rb_t *);
rb_t *LL(rb_t *);


//porperty mantaning
rb_t *property_handling(rb_t *);
rb_t *case1(rb_t *);
rb_t *case2(rb_t *);
rb_t *case3(rb_t *);
rb_t *case4(rb_t *);
rb_t *case5(rb_t *);

// Red-black specifc functions
rb_t *get_grandparent(rb_t *);
rb_t *get_uncle(rb_t *);
int get_color(rb_t *);

// Core tree operations
rb_t *newnode(int);
rb_t *rb_insert(rb_t *, int);

// general tree operations
void preorder(rb_t *);

#endif
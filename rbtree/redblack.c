#include "redblack.h"

rb_t *get_grandparent(rb_t *root){
    if (root->parent)
    {
        /* code */
    }
    
    rb_t *g = root->parent->parent;
    return g;
}
rb_t *get_uncle(rb_t *root){


    return;
}
int get_color(rb_t *root){


    return;
}
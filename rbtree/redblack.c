#include "redblack.h"

rb_t *newnode(int key)
{
    rb_t *node = (rb_t *)malloc(sizeof(rb_t));

    node->color = RED;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

rb_t *RR(rb_t *root){
    rb_t *b = root->right;
    rb_t *bleft = b->left;

    b->left = root;
    b->parent = root->parent;
    root->right = bleft;
    root->parent = b;
    if (bleft)
    {
        b->parent = root;
    }
    
    return b;
}
rb_t *LL(rb_t *root){

    return root;
}

rb_t *get_grandparent(rb_t *root)
{
    if ((root) && (root->parent))
        return root->parent->parent;
    else
        return NULL;
}

rb_t *get_uncle(rb_t *root)
{
    rb_t *g = get_grandparent(root);
    if (!g)
        return NULL;
    else if (g->right == root->parent)
        return g->left;
    else
        return g->right;
}

rb_t *rb_insert(rb_t *root, int key)
{
    if (root == NULL)
    {
        return newnode(key);
    }
    else if (key < root->key)
    {
        root->left = rb_insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = rb_insert(root->right, key);
    }

    return root;
}

void preorder(rb_t *root)
{
    if (root)
    {
        printf("|%d| ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
#include "avl.h"

void preorder(avl_t *root)
{
    if (root)
    {
        printf("|%d|", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void order(avl_t *root)
{
    if (root)
    {
        preorder(root->left);
        printf("|%d|", root->key);
        preorder(root->right);
    }
}
void postorder(avl_t *root)
{
    if (root)
    {
        preorder(root->left);
        preorder(root->right);
        printf("|%d|", root->key);
    }
}

avl_t *avl_min(avl_t *root)
{
    while (root->left)
    {
        root = root->left;
    }

    return root;
}
avl_t *avl_max(avl_t *root)
{
    while (root->right)
    {
        root = root->right;
    }

    return root;
}
avl_t *newnode(int key)
{
    avl_t *newnode = (avl_t *)malloc(sizeof(avl_t));
    newnode->height = 1;
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

int avl_height(avl_t *root)
{
    if (!root)
        return 0;
    return root->height;
}

int calculatefb(avl_t *root)
{
    if (!root)
        return 0;
    return avl_height(root->left) - avl_height(root->right);
}

avl_t *LL(avl_t *root)
{
    avl_t *b = root->left;
    avl_t *bright = b->right;

    root->left = bright;
    b->right = root;

    root->height = MAX(avl_height(root->left), avl_height(root->right)) + 1;
    b->height = MAX(avl_height(b->left), avl_height(b->right)) + 1;

    return b;
}

avl_t *RR(avl_t *root)
{
    avl_t *b = root->right;
    avl_t *bleft = b->left;

    root->right = bleft;
    b->left = root;

    root->height = MAX(avl_height(root->left), avl_height(root->right)) + 1;
    b->height = MAX(avl_height(b->left), avl_height(b->right)) + 1;

    return b;
}

avl_t *avl_insert(avl_t *root, int key)
{
    if (!root)
        return newnode(key);
    else if (key < root->key)
        root->left = avl_insert(root->left, key);
    else if (key > root->key)
        root->right = avl_insert(root->right, key);
    else
        return root;

    root->height = MAX(avl_height(root->left), avl_height(root->right)) + 1;
    int fb = calculatefb(root);

    if (fb > 1 && key < root->left->key)
    {
        root = LL(root);
    }
    if (fb < -1 && key > root->right->key)
    {
        root = RR(root);
    }
    else if (fb > 1 && key > root->left->key)
    {
        root->left = RR(root->left);
        root = LL(root);
    }
    else if (fb < -1 && key < root->right->key)
    {
        root->right = LL(root->right);
        root = RR(root);
    }

    return root;
}

avl_t *avl_search(avl_t *root, int key)
{
    if (key == root->key || !root)
    {
        return root;
    }
    else if (key < root->key)
        root = avl_search(root->left, key);
    else
        root = avl_search(root->right, key);
}

avl_t *avl_delete(avl_t *root, int key);

// int avl_depth(avl_t *root)
// {
// }
// int avl_width(avl_t *root)
// {
// }
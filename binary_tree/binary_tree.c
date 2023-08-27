#include "binary_tree.h"

int bin_height(bin_t *root) //  adaptar para o conceito do professor
{
    if (!root)
    {
        return 0;
    }
    int leftH = bin_height(root->left) + 1;
    int rightH = bin_height(root->right) + 1;

    return MAX(leftH, rightH);
}

int bin_depth(bin_t *root)
{
    if (!root)
    {
        return 1;
    }
    int leftH = bin_height(root->left) + 1;
    int rightH = bin_height(root->right) + 1;

    return MAX(leftH, rightH);
}

void preorder(bin_t *root)
{
    if (root)
    {
        printf("|%d|", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void order(bin_t *root)
{
    if (root)
    {
        preorder(root->left);
        printf("|%d|", root->key);
        preorder(root->right);
    }
}
void postorder(bin_t *root)
{
    if (root)
    {
        preorder(root->left);
        preorder(root->right);
        printf("|%d|", root->key);
    }
}

bin_t *bin_min(bin_t *root)
{
    while (root->left)
    {
        root = root->left;
    }

    return root;
}
bin_t *bin_max(bin_t *root)
{
    while (root->right)
    {
        root = root->right;
    }

    return root;
}

bin_t *bin_newnode(int key)
{
    bin_t *newnode = (bin_t *)malloc(sizeof(bin_t));
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
bin_t *bin_search(bin_t *root, int key)
{
    if (key == root->key || !root)
    {
        return root;
    }
    else if (key < root->key)
        root = bin_search(root->left, key);
    else
        root = bin_search(root->right, key);
}

bin_t *bin_insert(bin_t *root, int key)
{
    if (!root)
        return bin_newnode(key);
    else if (key < root->key)
        root->left = bin_insert(root->left, key);
    else if (key > root->key)
        root->right = bin_insert(root->right, key);
    else
        return root;

    return root;
}

bin_t *bin_delete(bin_t *root, int key)
{
    if (!root)
        return root;
    else if (key < root->key)
        root->left = bin_delete(root->left, key);
    else if (key > root->key)
    {
        root->right = bin_delete(root->right, key);
    }
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        else if (!root->right)
        {
            bin_t *temp = root->left;
            free(root);

            return temp;
        }
        else if (!root->left)
        {
            bin_t *temp = root->right;
            free(root);

            return temp;
        }
        else
        {
            bin_t *temp = bin_min(root->right);
            root->key = temp->key; // copy data
            root->right = bin_delete(root->right, root->key);
        }
    }
    return root;
}
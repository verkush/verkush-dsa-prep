#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}node;

node * getNewNode(node * root, int value)
{
    node * newNode = (node *) malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node * insertBST(node *root, int value)
{
    if (root == NULL)
    {
        return getNewNode(root, value);
    }
    if (root->data < value)
    {
        root->right = insertBST(root->right, value);
    }
    else if (root->data > value)
    {
        root->left = insertBST(root->left, value);
    }

    return root;
}

void inorderTraversal(node * root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int searchNodeBST(node * root, int value)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == value)
    {
        return 1;
    }
    if (root->data < value)
    {
        return searchNodeBST(root->right, value);
    }
    else 
    {
        return searchNodeBST(root->left, value);
    }
}

int getRightMin(node * root)
{
    node * temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

node * removeNodeBST(node * root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < value)
    {
        root->right = removeNodeBST(root->right, value);
    }
    else if (root->data > value)
    {
        root->left = removeNodeBST(root->left, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            node * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node * temp = root->left;
            free(root);
            return temp; 
        }
        else
        {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = removeNodeBST(root->right, rightMin);

        }
    }

    return root;
}

int main()
{
    node *root = NULL;

    root = insertBST(root, 100);
    root = insertBST(root, 10);
    root = insertBST(root, 50);
    root = insertBST(root, 300);
    root = insertBST(root, 30);

    inorderTraversal(root);

    int item = searchNodeBST(root, 50);
    printf("\n%d\n", item);

    root = removeNodeBST(root, 50);

    inorderTraversal(root);


    return 0;
}
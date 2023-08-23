#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) 
	{
        return createNode(value);
    }

    if (value < root->data) 
	{
        root->left = insert(root->left, value);
    } else if (value > root->data)
	{
        root->right = insert(root->right, value);
    }

    return root;
}
struct Node* search(struct Node* root, int value) 
{
    if (root == NULL || root->data == value) 
	{
        return root;
    }

    if (value < root->data) 
	{
        return search(root->left, value);
    }

    return search(root->right, value);
}
struct Node* findMin(struct Node* root) 
{
    if (root == NULL || root->left == NULL) 
	{
        return root;
    }

    return findMin(root->left);
}
struct Node* findMax(struct Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }

    return findMax(root->right);
}

int main() 
{
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int searchValue = 40;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) 
	{
        printf("Element %d found in the BST.\n", searchValue);
    } else {
        printf("Element %d not found in the BST.\n", searchValue);
    }

    struct Node* minNode = findMin(root);
    printf("Minimum element in the BST: %d\n", minNode->data);

    struct Node* maxNode = findMax(root);
    printf("Maximum element in the BST: %d\n", maxNode->data);

    return 0;
}

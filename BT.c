#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} NODE;

NODE* createNode(int val) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertLeft(NODE* parent, int val) {
    if (parent->left != NULL) {
        printf("Left child already exists for %d\n", parent->data);
        return;
    }
    parent->left = createNode(val);
    printf("Inserted %d to LEFT of %d\n", val, parent->data);
}

void insertRight(NODE* parent, int val) {
    if (parent->right != NULL) {
        printf("Right child already exists for %d\n", parent->data);
        return;
    }
    parent->right = createNode(val);
    printf("Inserted %d to RIGHT of %d\n", parent->data, val);
}

void insert(NODE* parent, int val) {
    int ch;
    printf("Where to insert %d for parent %d?\n", val, parent->data);
    printf("1. Left\n2. Right\nEnter choice: ");
    scanf("%d", &ch);

    if (ch == 1)
        insertLeft(parent, val);
    else if (ch == 2)
        insertRight(parent, val);
    else
        printf("Invalid option\n");
}

void preorder(NODE* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int val;
    NODE* root = NULL;

    printf("Enter root value: ");
    scanf("%d", &val);
    root = createNode(val);

    insert(root, 20);
    insert(root, 30);
    insert(root->left, 40);
    insert(root->right, 50);

    printf("\nPreorder Traversal: ");
    preorder(root);

    return 0;
}

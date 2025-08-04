#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int key;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void fixInsert(Node** root, Node* k) {
    Node* parent = NULL;
    Node* grandparent = NULL;

    while ((k != *root) && (k->color != BLACK) && (k->parent->color == RED)) {
        parent = k->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                if (k == parent->right) {
                    leftRotate(root, parent);
                    k = parent;
                    parent = k->parent;
                }
                rightRotate(root, grandparent);
                Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                k = parent;
            }
        } else {
            Node* uncle = grandparent->left;

            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                if (k == parent->left) {
                    rightRotate(root, parent);
                    k = parent;
                    parent = k->parent;
                }
                leftRotate(root, grandparent);
                Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                k = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

Node* insert(Node** root, Node* rootNode, int key) {
    if (rootNode == NULL)
        return newNode(key);

    if (key < rootNode->key) {
        rootNode->left = insert(root, rootNode->left, key);
        rootNode->left->parent = rootNode;
    } else if (key > rootNode->key) {
        rootNode->right = insert(root, rootNode->right, key);
        rootNode->right->parent = rootNode;
    } else
        return rootNode;

    return rootNode;
}

void insertNode(Node** root, int key) {
    *root = insert(root, *root, key);

    Node* current = *root;
    Node* inserted = NULL;
    while (current != NULL) {
        if (key == current->key) {
            inserted = current;
            break;
        } else if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    fixInsert(root, inserted);
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d(%s) ", root->key, root->color == RED ? "R" : "B");
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int values[] = {10, 20, 30, 15, 25, 5, 1};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        insertNode(&root, values[i]);

    printf("Inorder traversal of Red-Black Tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}
// 3.22 Write a program to convert a binary search tree into a linked list
/*
    - First traverse the left subtree, then visit the root, then traverse the right subtree
    - Visiting the nodes recursively in accord procudes an in order traversal
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocate memory in the heap
    n->data = data; // Setting the data
    // set both of the left and right children to NULL
    n->left = NULL;
    n->right = NULL;
    return n; // return the created node
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
        
    }
}

int main() {
    // Constructing the root node - Using Function
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  
}
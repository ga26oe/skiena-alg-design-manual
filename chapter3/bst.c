#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define a type for items (assuming int here, but you can change as needed)
typedef int item_type;

/* Creatin a binary search tree
    - Basic operations are: searching, traversing, insertions, and deletion
*/

typedef struct tree {
    item_type item; /* data item*/
    struct tree *parent; /* pionter to parent*/
    struct tree *left; /* pointer to left child*/
    struct tree *right; /* pointer to right child*/

} tree;

/* Seaching in a tree
    - Start at the root
    - Unless it contains the query x, proceed either left or right depending on whether x occurs
        before or after the root key
    - Both the left and right subtrees of a binary search trees are themselves binary search trees
    - This means you can use a recursive structure
    - This runs in O(h) time, where h is the height of the tree
*/

tree *search_tree(tree *l, item_type x) 
{
    if (l == NULL) return (NULL);

    if (l->item == x) return (1);

    if (x < l->item)
        return(search_tree(l->left, x));
    else   
        return(search_tree(l->right, x));

}

/* Finding the minumum element is the left most node of the three
    Find the maximum elemeent is the right most node of the tree
*/

tree *find_minimum(tree *t) 
{
    tree *min; /* pointer to min*/

    if (t == NULL) return (NULL);

    min = t;
    while (min ->left != NULL)
        min = min->left;
    return(min);
}

/* in order traversal of binary search tree*/
void traverse_tree(tree *l) 
{
    if (l != NULL) {
        traverse_tree(l->left);
        process_time(l->item);
        traverse_tree(l->right);
    }
}

/* Inserting in a tree
    - You must replace the NULL pionter after an unsuccesful query for key k
    - use recursion to combine search and node insertion
    - three arguments you need
        1. pointer l to pointer linking the search subtree to rest of the tree
        2. key x to be inserted
        3. parent pointer to the parent node containing l
    - pass pointer to appropiate left/right pointer to the node during the search
    - *l = p linkes the new node into the tree    
*/

insert_tree(tree **l, item_type x, tree *parent) 
{
    tree *p;  /* temporary pointer*/

    if (*l == NULL) {
        p = malloc(sizeof(tree)); /* allocate new node */
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p; /* link into parent's record*/
        return;
    }

    if (x < (*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else    
        insert_tree(&((*l)->right), x, *l);
}

#include <stdio.h>
#include <stdlib.h>

typedef int item_type;

typedef struct list {
    item_type item; /*data item*/
    struct list *next; /*point to successor*/
} list;

/*
    - Each node in our data structure, which is a list, containts a pionter
    - The pointer is called next
    - much of ths space used in linked list data structures has to be devoted to pointers, not data
    - Need a pointer to the head of the structure, so we know where to access it

*/

/* 
    - Searching for an item in a list can be done iteratively or recusively
    - Below will be a recursive implementation
    "->" means take the pointer and access the member item it points to
*/

list *search_list(list *l, item_type x)
{
    if (l == NULL) return(NULL);

    if (l->item == x)
        return(1);
    else
        return( search_list(l->next, x));
}

/*
    - Insertion into a linked list -- you can use pointer manipulation
    - insert each new item to the simplest place -- the beginning
    - this avoids the need to traverse the list
    - to do this, update pointer to the head of the data structure
*/

void insert_list(list **l, item_type x) /* Insert a new node at the begining*/
{
    list *p; /* Create a ne wpointer p to hold the new node*/

    p = malloc( sizeof(list)); 
    p->item = x; /* store the value of x to the new node*/
    p->next = *l; /* make the new node point to the current head of the list*/
    *l = p; /* update the head pinter to point to the new node*/
}

/*
    - malloc allocated memoery of sufficient size for a new node to contain x
    - **l means l is a pointer to a pointer to a list node
    - We need a pointer of a pointer in order to modify a pointer
    - *l = p copies p to the place pointed to l, which is the external variable
        maintaining access to the head of the list
    
*/

/*
    - Deleting from a list is more engaging
    - Need a pointer to find the predecessor, which point to the item we want 
        to delete
    - after deleting, must reset the pionter head of the list
    - must also deallocate memory
*/

list *predecessor_list(list *l, item_type x) 
{
    if ((l == NULL) || (l->next == NULL)) { /* if list is empty or list only has 1 element (the next pointer to the first element in null)*/
        printf("Error: predecessor sought on null list.\n");
        return (NULL);
    }

    if ((l->next)->item ==x) /* if the pointer l contains the value equal to x */
        return(l);
    else   
        return(predecessor_list(l->next, x)); /* if not, recurisvely call function with the next node */
}

delete_list(list **l, item_type x)
{
    list *p; /* item pointer */
    list *pred; /* predecessor pointer*/
    list *search_list(), *predecessor_list();

    p = search_list(*l, x);
    if (p != NULL) {
        pred = predecessor_list(*l, x);
        if (pred == NULL) /* if there is no predecessors (first in list)*/
            *l = p->next; /* make head pointer point to the second node, effectively DELETING it by skipping over it*/
        else    
            pred->next = p->next; /* DELTES by updating predecessors next*/
        free(p); /* free memory used by node*/
    }
}
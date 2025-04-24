/* Write a program to reverse the direction of a given singly-linked list. In other words, 
after the reversal all pointer should now point backwwards. This should take linear time.
*/

/* uses the implicit stack implementation. 
    - Traverse the list and push all nodes except the last node
    - Make the last node the new head of the reversed linked list
    - Start popping the element and append each node to the reversed list
    - return the head of the reversed linked list
*/

#include <stdio.h>
#include <stdlib.h>

// create the node structure with a integer value and a pointer to the next node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data; // set the nodes data to the provided value
    new_node->next = NULL; // set the next pointer to NULL
    return new_node;
}

//Function to reverse the linked list
struct Node* reverseList(struct Node* head) {

    //crate a stack to store the nodes
    struct Node* stack[10000]; //Array to act as a stack
    int top = -1; // stack pointer, -1 means empty
    struct Node* temp = head; // temporary pointer to traverse list

    // Push all nodes excpt the last node into the stack
    while (temp != NULL) {
        stack[++top] = temp; // increment top and store node, ++top preincemrents 
        temp = temp->next; // move to the next node
    }

    if (top >= 0) { // if the stack is not empty
        head = stack[top]; // last node becomes new head
        temp = head; // temp points to new head

        // Pop all the nodes and append to the linked list
        while (top > 0) {
            // append the top value of stack in list 
            // pop the value by decrementing top by 1
            temp->next = stack[--top];
            
            // move the next node in the list
            temp = temp->next;
        }

        //update the next pointer of last ndoe of stack to NULL
        temp->next = NULL;
    }

    return head;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    //Create hard coded linked list
    //1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Given Linked List:");
    printList(head);

    head = reverseList(head);

    printf("\nReversed Linked List:");
    printList(head);

    return 0;
}
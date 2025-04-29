// Write a function to find the middle node of a singly-linked list. 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Helper Functions fo find length of linked list; Naive approach
int getLength(struct Node *head) {
    //Variable to store length
    int length = 0;

    //Traverse the entire linked list and increment length
    while (head) {
        length++;
        head = head->next;
    }

    // Return the number of nodes in the linked list
    return length;
}

//Function to find the middle element of the linked list
int getMiddle(struct Node *head) {
    //Finding the length of the linked list
    int length = getLength(head);

    //traverse till we reach half of the length
    int mid_index = length / 2;
    while (mid_index--) {
        head = head->next;
    }

    //Head will now be pointing to the middle element
    return head->data;
}

// Tortoise and Hare Algorithm (Floyd Cycle Finding) to find middle element
int getMiddleV2(struct Node *head){

    // Initialize slow and fast pointer to the head of the linked list
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    // traverse the linked list
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        
        // Move fast ptr by two nodes
        fast_ptr = fast_ptr->next->next;
        
        // Move the slow pointer by one node
        slow_ptr = slow_ptr->next;
    }
    // return the slow pointer which is current pointing to the middle of the node
    return slow_ptr->data;

}

struct Node *createNode(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    //Create hard-coded linked list
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60 
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    printf("%d\n", getMiddle(head));

    return 0;
}
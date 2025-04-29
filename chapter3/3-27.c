// Determine wheter a linked list contains a loop as quickly as possible
// without using extra storage. Identify the location of the loop

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};



// Tortoise and Hare Algorithm (Floyd Cycle Finding)
struct Node *detectCycle(struct Node *head){

    // If list is empty or has one Node
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // Initialize slow and fast pointer to the head of the linked list
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;


    // PHASE 1: Detect if there is a cycle
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        
        // Move fast ptr by two nodes
        fast_ptr = fast_ptr->next->next;
        
        // Move the slow pointer by one node
        slow_ptr = slow_ptr->next;

        // There is a cycle if the fast ptr catches up to the slow ptr
        if (fast_ptr->data == slow_ptr->data) {
            break;

        }

        // If no cycle was fond
        if (fast_ptr == NULL || fast_ptr->next == NULL) {
            return NULL;
        }
    }
    // return the slow pointer which is current pointing to the middle of the node
    return slow_ptr;

    // Second Phase: find the start of the cycle
    slow_ptr = head; // reset slow ptr to head and have both pointers move in one step
    while (slow_ptr != fast_ptr) {
        slow_ptr ->next;
        fast_ptr ->next;
    }

    return slow_ptr;

}

struct Node *createNode(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create hard-coded linked list with a cycle
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60
    //                   ^             |
    //                   |_____________|
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    // Create a cycle by connecting the last node to the node containing 40
    head->next->next->next->next->next->next = head->next->next->next;

    //detect cycle:
    struct Node *cycleStart = detectCycle(head);

    if (cycleStart != NULL) {
        printf("Cycle detectd starting at node with data; %d\n", cycleStart->data);

    } else {
        printf("No cycle found in the linked list\n");
    }

    return 0;
}
// Reverse the words in a sentence. "My name is Chris" becomes "Chris is name My"
// Optimize for time and space

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Maximum capacity of stack
#define MAX_SIZE 100
#define MAX_WORD_LENGTH 50
typedef struct
{
    // Array to store stack elements
    char words[MAX_SIZE][MAX_WORD_LENGTH];
    // index of the top of the element in the stack
    int top;
} Stack;

// Function to initiliaze stack
void init(Stack *stack)
{
    // set top index to -1 to indicate empty stack
    stack->top = -1;
}
 
bool isEmpty(Stack *stack)
{
    // if top is -1, the stack is empty
    return stack->top == -1;
}

// function to check if the stack is full
bool isFull(Stack *stack)
{
    // if top is MAX_SIZE -1, then the stack is full
    return stack->top == MAX_SIZE - 1;
}
// Function to push an element onto the stack
void push(Stack *stack, const char *word)
{
    // check for stack overflow
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }

    // increment top and add value to the top of the stack
    stack->top++; // increment first
    strcpy(stack->words[stack->top], word);
}

char *pop(Stack *stack)
{
    // check for stack overflow
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return NULL;
    }

    // return the top element and decrement top
    return stack->words[stack->top--];
}

void reverseWords(char *sentence)
{
    // Todo: Implement function to reverse words using stack
    Stack stack;
    init(&stack);

    // Temporary buffer to store each word
    char word[MAX_WORD_LENGTH];
    int wordIndex = 0;

    //Traverse the sentence character by character
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ') {
            word[wordIndex++] = sentence[i]; //word[0] = M wordIndex becomes 1
        } else if (wordIndex > 0) {
            // We found a space, end the current word
            word[wordIndex] = '\0'; //end the word with null termination
            push(&stack, word);
            wordIndex = 0;
        }
    }

    // push last word if it exists onto stack
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        push(&stack, word);
    }

    //clear the original setnence
    sentence[0] = '\0';

    // pop words and rebuilt the sentence
    while (!isEmpty(&stack)) {
        char *poppedWord = pop(&stack);
        if (poppedWord != NULL) {
            if (strlen(sentence) > 0) {
                strcat(sentence, " ");
            }
            strcat(sentence, poppedWord);
        }
    }

}

int main()
{
    char sentence[] = "My name is Chris";
    printf("Original sentence: %s\n", sentence);

    reverseWords(sentence);

    printf("Reversed sentence: %s\n", sentence);

    return 0;
}
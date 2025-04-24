/* Problem 3.1
A common problem for compilers and text editors is determining whether the parentheses in a string are balanced
and properly nested. For example, the string contains (()()) properly nested pairs of parentheses, which the strings )(())
and do not. Give an algorithm that returns true if a string contains properly nested and balanced parentheses, and
false if otherwise. For full credit, identify the position of the first offending parenthesis if the string is not
properly nested and balanced.
*/

#include <stdio.h>
#include <stdbool.h>

// Maximum capacity of stack
#define MAX_SIZE 100

// structure for the stack
typedef struct
{
    // Array to store stack elements
    int arr[MAX_SIZE];
    // index of the top element in the stack
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack)
{
    // set top index to -1 to indicate an empty stack
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
void push(Stack *stack, int value)
{
    // check for stack overflow
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }

    // increment top and add value to the top of the stack
    stack->arr[++stack->top] = value; /* increment first, then use the value*/
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *stack)
{
    // check for stack overflow
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    // return the top element
    int popped = stack->arr[stack->top];
    // decrement the top pointer
    stack->top--;
    printf("Popped %d from the stack\n", popped);
    // return the popped element
    return popped;
}

// function to peek the top element of the stack
int peek(Stack *stack)
{
    // check if the stack is empty
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }

    // return the top element without removing it
    return stack->arr[stack->top];
}

bool checkParentheses(const char *str, int *errorPos)
{
    Stack stack;
    initialize(&stack);

    for (int i = 0; str[i] != '\0'; i++)
    { /* in C, a string ends in /0 (null termination)*/
        if (str[i] == '(')
        {
            /* if string is open parenthesis, push into stack*/
            push(&stack, i);
        }
        else if (str[i] == ')')
        {
            // if stack is already empty, there is no matching parenthesis
            if (isEmpty(&stack))
            {
                *errorPos = i;
                return false;
            }
            pop(&stack);
        }
    }

    // Check if there are any unmatched opening parenthesis
    if (!isEmpty(&stack))
    {
        *errorPos = peek(&stack);
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    // check if an argument is provided
    if (argc != 2)
    {
        printf("Usage: %s <parentheses string>\n", argv[0]);
        return 1;
    }

    int errorPos = -1;
    if (checkParentheses(argv[1], &errorPos))
    {
        printf("Parenthesis are balances and properly nested.\n");
    }
    else
    {
        printf("Parentheses are not balances or nested\n");
        printf("First offending parenthesis are position %d\n", errorPos);

        // print the string with an indicator for the error position
        printf("%s\n", argv[1]);
        for (int i = 0; i < errorPos; i++)
        {
            printf(" ");
        }

        printf("^\n");
    }

    return 0;
}

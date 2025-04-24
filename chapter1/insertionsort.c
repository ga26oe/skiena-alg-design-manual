#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define a type for items (assuming int here, but you can change as needed)
typedef int item;

// Define the swap function
void swap(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(item s[], int n) {
    int i, j;
    for (i = 1; i < n; i++) { //start with 2nd element, assuming 1st is sorted
        j = i;
        while ((j > 0) && (s[j] < s[j-1])) {
            swap(&s[j], &s[j-1]);
            j = j-1;
        }
    }
}

// Example main function to test the sort
int main() {
    item arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    insertion_sort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
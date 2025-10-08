/*
 * week4_1_dynamic_array.c
 * Author: [Orkhan Hajizada]
 * Student ID: [241ADB170]
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
     int n;
    int *arr = NULL;
    int sum = 0;
    double average = 0.0;
    
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // TODO: Allocate memory for n integers using malloc
    arr = malloc(n * sizeof(int));

    // TODO: Check allocation success
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // TODO: Read n integers from user input and store in array
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // TODO: Compute sum and average
    average = (double)sum / n;

    // TODO: Print the results
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    // TODO: Free allocated memory
    free(arr);


    return 0;
}

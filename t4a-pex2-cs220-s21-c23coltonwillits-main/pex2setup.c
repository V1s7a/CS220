/** pex2setup.c
 * ===========================================================
 * Name:
 * Section:
 * Project: PEX2
 * Purpose: Sorting algoritms
 * =========================================================== */

#include "pex2setup.h"

/**
 * @brief Tests whether the list is sorted in ascending order or not
 * @param numbers the list of numbers
 * @param length number of items in the array
 * @param order 0 for ascending, 1 for descending
 * @return 0 if the list is not sorted, 1 if it is sorted
 * @pre numbers contains some set of integers >= 0
 * @post return whether the list is sorted in ascending order
 */
int testSorted(int numbers[], int length, int order) {
    int i;
    for (i = 1; i < length; i++) {
        if (order == 0) {
            if (numbers[i] < numbers[i - 1]) {
                return 0;
            }
        } else {
            if (numbers[i] > numbers[i - 1]) {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * @brief Generates a list of random numbers
 * @param size the size of the random list to generate
 * @return an array of random numbers
 * @pre size is greater than zero
 * @post an array is returned with size amount of elements containing random data
 */
int *generateRandomArray(int size) {
    srand((unsigned)2354);

    int *theArray = (int *)malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++) {
        theArray[i] = rand();
    }
    return theArray;
}

/**
 * @brief Displays the array of numbers to the user
 * @param numbers the list of numbers
 * @param length number of items in the array
 * @pre numbers contains some set of values
 * @post numbers are displayed to the screen
 */
void printArray(int *numbers, int length) {
    int i;
    for (i = 1; i < length; i++) {
        printf("%d ", numbers[i]);
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

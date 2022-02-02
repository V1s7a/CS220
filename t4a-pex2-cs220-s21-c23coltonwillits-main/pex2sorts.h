/** pex2sorts.h
 * ===========================================================
 * Name:
 * Section:
 * Project: PEX2
 * Purpose: Sorting algoritms
 * Documentation:
 * =========================================================== */

#ifndef PEX2SORTS_H
#define PEX2SORTS_H

/**
 * @brief Sorts based on selection sort algorithm
 * @param array the list of numbers
 * @param N number of items in the array
 */
void selectionSort(int array[], int N);

/**
 * @brief Sorts based on selection insertion sort algorithm
 * @param array the list of numbers
 * @param N number of items in the array
 */
void insertionSort(int array[], int N);

/**
 * @brief Sorts based on bubble sort algorithm
 * @param array the list of numbers
 * @param N number of items in the array
 */
void bubbleSort(int array[], int N);

/**
 * @brief Sorts based on merge sort algorithm
 * @param array the list of numbers
 * @param N number of items in the array
 */
void mergeSort(int array[], int N);

#endif
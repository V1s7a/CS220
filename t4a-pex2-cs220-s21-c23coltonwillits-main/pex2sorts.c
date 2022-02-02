/** pex2sorts.c
 * ===========================================================
 * Name: Colton Willits
 * Section: T4A
 * Project: PEX2
 * Purpose: Sorting algoritms
 * Documentation: Colton Willits (reference lab06, lab07, lab08), Zybooks
 * =========================================================== */
#include "pex2sorts.h"

void invert(int array[], int N) {
    for (int i = 0, x = N - 1; i < x; i++, x--) {
        int temp = array[i];
        array[i] = array[x];
        array[x] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int numbers[], int lBound, int rBound) {
    int j = 0;

    if (lBound < rBound) {
        j = (lBound + rBound) / 2;

        merge_sort(numbers, lBound, j);
        merge_sort(numbers, j + 1, rBound);
        merge(numbers, lBound, j, rBound);
    }
}

void selectionSort(int array[], int N) {
    int i, b, min;
    for (i = 0; i < N - 1; i++) {
        min = i;
        for (b = i + 1; b < N; b++) {
            if (array[b] < array[min])
                min = b;
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
    invert(array, N);
}

void insertionSort(int array[], int N) {
    int i, num, b;
    for (i = 1; i < N; i++) {
        num = array[i];
        b = i - 1;
        while (b >= 0 && array[b] > num) {
            array[b + 1] = array[b];
            b = b - 1;
        }
        array[b + 1] = num;
    }
    invert(array, N);
}

void bubbleSort(int array[], int N) {
    int i, j, temp;
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    invert(array, N);
}

void mergeSort(int array[], int N) {
    merge_sort(array, 0, N);
    invert(array, N);
}
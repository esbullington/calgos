#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

void swap(int *i, int *j)
{
    int k = *i;
    *i = *j;
    *j = k;
}

void partition(int *array, int start_of_array, int end_of_array)
{
    int pivot, cursor, i;

    if (start_of_array >= end_of_array) return;

    pivot = array[end_of_array];
    cursor = start_of_array;
    i = start_of_array;

    while (i <= end_of_array) {
        if (array[i] <= pivot) {
            swap(&array[cursor], &array[i]);
            if (i != end_of_array) cursor++;
            
        }
        i++;
    }

    partition(array, start_of_array, cursor - 1);
    partition(array, cursor + 1, end_of_array);
    return;
}

void quicksort(int *array, size_t count)
{
    // base condition. If the array count < 2, stop recursing
    if (count < 2) return;
    partition(array, 0, count - 1);
}

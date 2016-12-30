#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"


void merge(int *array, int *left, int left_count,
        int *right,int right_count)
{
    // i: marks the index of first subarray (left)
    // j: marks the index of second subarray (right)
    // k: marks the index of merged subarray (array)
    int i, j, k;
    i = 0; j = 0; k =0;

    while(i < left_count && j < right_count) {
        if(left[i]  < right[j]) {
            array[k] = left[i];
            k++; i++;
        } else{
            array[k] = right[j];
            k++; j++;
        }
    }

    // Append subarrays back onto main array
    while(i < left_count) {
        array[k] = left[i];
        k++; i++;
    }
    while(j < right_count) {
        array[k] = right[j];
        k++; j++;
    }
}

bool mergesort(int *array, size_t count)
{
    // empty array: undefined behavior
    if (count < 1) return false;

    int mid, *left, *right;
    // base condition. If the array count < 2, stop recursing
    if (count < 2) return true;

    mid = count/2;

    // split it!
    // tArrays type contains the two subarrays after bisection
    tArrays *a = bisect_array(array, count);
    if (!a) {
        perror("Mergesort failed");
        exit(EXIT_FAILURE);
    }
    left = a->first_half;
    right = a->second_half;

    // recursively partition the array to the left or "left"
    mergesort(left, mid);
    // recursively partition the array to the right or "right"
    mergesort(right, count - mid);
    // then, recursively merge left and right
    // back into the array as sorted list.
    merge(array, left, mid, right, count - mid); 

    free(a);
    free(left);
    free(right);

    return true;
}

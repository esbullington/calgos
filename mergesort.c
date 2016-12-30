#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


void merge(int *array, int *first_half, int left_count,
           int *second_half,int right_count)
{
	// i: marks the index of first subarray (first_half)
	// j: marks the index of second subarray (second_half)
	// k: marks the index of merged subarray (array)
	int i, j, k;
	i = 0; j = 0; k =0;

	while(i < left_count && j < right_count) {
		if(first_half[i]  < second_half[j]) {
            array[k] = first_half[i];
            k++; i++;
        } else{
            array[k] = second_half[j];
            k++; j++;
        }
	}

    // Append subarrays back onto main array
	while(i < left_count) {
        array[k] = first_half[i];
        k++; i++;
    }
	while(j < right_count) {
        array[k] = second_half[j];
        k++; j++;
    }
}

void mergesort(int *array, size_t count)
{
	int mid, *first_half, *second_half;
    // base condition. If the array count < 2, stop recursing
	if (count < 2) return;

	mid = count/2;

    // split it!
    // tArrays type contains the two subarrays after bisection
    tArrays *a = bisect_array(array, count);
    if (!a) {
        perror("Mergesort failed");
        exit(EXIT_FAILURE);
    }
	first_half = a->first_half;
	second_half = a->second_half;

    // recursively partition the array to the left or "first_half"
	mergesort(first_half, mid);
    // recursively partition the array to the right or "second_half"
	mergesort(second_half, count - mid);
    // then, recursively merge first_half and second_half
    // back into the array as sorted list.
	merge(array, first_half, mid, second_half, count - mid); 

    free(a);
	free(first_half);
	free(second_half);
}

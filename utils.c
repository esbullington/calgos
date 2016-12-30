#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


tArrays *bisect_array_init(int *array, size_t size)
{
    tArrays *a;
    a = malloc(sizeof(tArrays));
    if (!a) {
        return NULL;
    }
    a->array = array;
    a->size = size;
}

tArrays *bisect_array(int *array, size_t size)
{
    tArrays *a = bisect_array_init(array, size);

    if (!a) {
        return NULL;
    }

    if (a->size % 2 == 0) {
        a->first_half_size = a->size/2;
        a->second_half_size = a->size/2;
    } else {
        a->first_half_size = a->size/2 + 1;
        a->second_half_size = a->size/2;
    }

    a->first_half = malloc(a->first_half_size * sizeof(int));
    if (!a->first_half) {
        return NULL;
    }

    a->second_half = malloc(a->second_half_size * sizeof(int));
    if (!a->second_half) {
        return NULL;
    }

    memcpy(a->first_half, a->array, a->first_half_size * sizeof(int));
    memcpy(a->second_half, a->array + a->first_half_size, a->second_half_size * sizeof(int));

    return a;
}


#ifndef UTILS_H_   /* Include guard */
#define UTILS_H_

typedef struct {
    int *array;
    size_t size;
    int *first_half;
    size_t first_half_size;
    int *second_half;
    size_t second_half_size;
} tArrays;

tArrays *bisect_array(int *array, size_t size);

#endif // UTILS_H_

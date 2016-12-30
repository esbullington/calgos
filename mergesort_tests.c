
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"
#include "CuTest.h"

void test_mergesort(CuTest *tc)
{
    int array[] = {1,2,444,9,4,5,6,7};
    size_t count = sizeof(array)/sizeof(array[0]);

	mergesort(array, count);

    /* size_t i; */
    /* //Printing of all elements of split arrays */
    /* printf("Array:\n"); */
    /* for (i = 0; i < count; i++) { */
    /*     printf("arr[%d] = %d\n", i, array[i]); */
    /*  */
    /* } */

    int expected = 444;
    int val = array[count-1];
	CuAssertIntEquals(tc, expected, val);
}

CuSuite* MergesortSuite()
{
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, test_mergesort);
    return suite;
}

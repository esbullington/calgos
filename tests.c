#include <stdio.h>
#include "CuTest.h"
#include "linkedlist_tests.h"
#include "hashtable_tests.h"
#include "mergesort_tests.h"

CuSuite* StrUtilGetSuite();

void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, LinkedListSuite());
    CuSuiteAddSuite(suite, HashtableSuite());
    CuSuiteAddSuite(suite, MergesortSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(void) {
    RunAllTests();
}

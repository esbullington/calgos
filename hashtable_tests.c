#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include "CuTest.h"

void test_hashtable_get(CuTest *tc)
{
    tHashtable *ht;

    ht = malloc( sizeof (tHashtable));

    if (ht == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    hashtable_init(ht);

    hashtable_set(ht, "testk", "testv");
    char *val = malloc(256);
    hashtable_get(ht, "testk", &val);
    char *expected = "testv";
	CuAssertStrEquals(tc, expected, val);
}

void test_hashtable_get_collisions(CuTest *tc)
{
    tHashtable *ht;

    ht = malloc( sizeof (tHashtable));

    if (ht == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    hashtable_init(ht);

    hashtable_set(ht, "playright", "testdram");
    hashtable_set(ht, "snush", "testvivency");
    char *val = malloc(256);
    hashtable_get(ht, "playright", &val);
    char *expected = "testdram";
	CuAssertStrEquals(tc, expected, val);
}

CuSuite* HashtableSuite()
{
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, test_hashtable_get);
	SUITE_ADD_TEST(suite, test_hashtable_get_collisions);
    return suite;
}

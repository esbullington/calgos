
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "hashtable.h"

#define MAX_ARRAY 1000

/* D. J. Bernstein hash function */
size_t djb_hash(char *str)
{
	size_t hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash;
}


bool hashtable_init(tHashtable *ht) {
	char *arr[MAX_ARRAY] = { NULL };
    ht->arr = arr;
	return true;
}

bool hashtable_set(tHashtable *ht, char *key, char *value)
{
    size_t count, probe_by, hashed_key;

	hashed_key = djb_hash(key) % MAX_ARRAY;

	if (ht->arr[hashed_key] == NULL) {
		ht->arr[hashed_key] = value;
		return true;
	} 

	count = 1;
	while (true) {
		probe_by = (pow(count, 2)) + hashed_key;
		if (probe_by >= MAX_ARRAY) {
			perror("tHashtable write error");
			return false;
		}
		if (ht->arr[probe_by] == NULL) {
			ht->arr[probe_by] = value;
            return true;
		}
        count++;
	}

    // Should never get here
    return false;

}

bool hashtable_get(tHashtable *ht, char *key, char **value)
{
    size_t count, probe_by, hashed_key;

	hashed_key = djb_hash(key) % MAX_ARRAY;

	if (ht->arr[hashed_key] != NULL) {
        strcpy(*value, ht->arr[hashed_key]);
        return true;
    }

	count = 1;
	while (true) {
		probe_by = (pow(count, 2)) + hashed_key;
		if (probe_by >= MAX_ARRAY) {
			perror("tHashtable read error");
			return false;
		}
		if (ht->arr[probe_by] == NULL) {
            strcpy(*value, ht->arr[probe_by]);
            return true;
		}
        count++;
	}

    return false;

}

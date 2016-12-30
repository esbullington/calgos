
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "hashtable.h"

/* D. J. Bernstein hash function */
size_t djb_hash(tHashtable *ht, char *str) {
	unsigned long hash = 5381;
	size_t i = 0;
	while (str[i] != '\0') {
		hash = ((hash << 5) + hash) + (*str);
		i++;
	}
	return hash % ht->size;
}

bool hashtable_init(tHashtable *ht, size_t size) {

	char *ptr;
	char **arr = malloc(sizeof(ptr) * size);
	size_t i;

	for (i = 0; i < size; i++) {
		arr[i] = NULL;
	}

    ht->arr = arr;
    ht-> size = size;
	return true;
}

bool hashtable_set(tHashtable *ht, char *key, char *value)
{
    size_t count, probe_by, hashed_key;

	hashed_key = djb_hash(ht, key);

	if (ht->arr[hashed_key] == NULL) {
		ht->arr[hashed_key] = value;
		return true;
	} 

	count = 1;
	while (true) {
		probe_by = (pow(count, 2)) + hashed_key;
		if (probe_by >= ht->size) {
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

	hashed_key = djb_hash(ht, key);

	if (ht->arr[hashed_key] != NULL) {
        strcpy(*value, ht->arr[hashed_key]);
        return true;
    }

	count = 1;
	while (true) {
		probe_by = (pow(count, 2)) + hashed_key;
		if (probe_by >= ht-> size) {
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

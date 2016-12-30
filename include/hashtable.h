
#ifndef HASHTABLE_H_   /* Include guard */
#define HASHTABLE_H_

typedef struct {
    char **arr;
    size_t size;
} tHashtable;

bool hashtable_init(tHashtable *ht, size_t size);
bool hashtable_set(tHashtable *ht, char *key, char *value);
bool hashtable_get(tHashtable *ht, char *key, char **value);

#endif // HASHTABLE_H_

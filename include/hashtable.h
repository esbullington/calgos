
#ifndef HASHTABLE_H_   /* Include guard */
#define HASHTABLE_H_

typedef struct {
    char **arr;
} tHashtable;

bool hashtable_init(tHashtable *ht);
bool hashtable_set(tHashtable *ht, const char *key, char *value);
bool hashtable_get(tHashtable *ht, const char *key, char **value);

#endif // HASHTABLE_H_

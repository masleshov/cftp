#include "stdbool.h"

// true if equals, false if not equals
typedef bool (*key_comparer_t)(void*, void*);

typedef enum HashTableResult
{
    SUCCESS = 0,
    ALREADY_EXISTS = -1
} HashTableResult;

typedef struct hashtable hashtable_t;

hashtable_t* hashtable_new();
HashTableResult hashtable_add(hashtable_t* table, void* key, void* obj, key_comparer_t comparer);
void* hashtable_get(hashtable_t* table, void* key, key_comparer_t comparer);
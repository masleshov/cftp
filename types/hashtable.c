#include "stddef.h"
#include "stdint.h"
#include "linkedlist.h"
#include "hashtable.h"

typedef struct hashtable_entry
{
    void* key;
    void* val;
} hashtable_entry_t;

typedef struct hashtable
{
    intptr_t original;
    linkedlist_t* buckets[10];
} hashtable_t;

int get_hash(intptr_t key, int buckets_count)
{
    if(buckets_count == 0)
    {
        return key;
    }

    return key%buckets_count;
}

hashtable_t* hashtable_new()
{
    hashtable_t* table = malloc(sizeof(hashtable_t));
    table->original = table->buckets;
    return table;
}

HashTableResult hashtable_add(hashtable_t* table, void* key, void* obj, key_comparer_t comparer)
{
    int bucket = get_hash(&key, 10);
    if(table->buckets[bucket] == NULL)
    {
        table->buckets[bucket] = linkedlist_new();
    }

    hashtable_entry_t* current;
    while((current = linkedlist_get_next(table->buckets)) != NULL)
    {
        if(comparer(key, current->key))
        {
            return ALREADY_EXISTS;
        }
    }

    current = malloc(sizeof(hashtable_entry_t));
    current->key = key;
    current->val = obj;
    linkedlist_add_first(table->buckets[bucket], current);

    return SUCCESS;
}

void* hashtable_get(hashtable_t* table, void* key, key_comparer_t comparer)
{
    int bucket = get_hash(&key, 10);
    if(table->buckets[bucket] == NULL)
    {
        return NULL;
    }

    hashtable_entry_t* current;
    while((current = linkedlist_get_next(table->buckets[bucket])) != NULL)
    {
        if(comparer(key, current->key))
        {
            return current->val;
        }
    }

    return NULL;
}
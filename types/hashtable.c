#include "string.h"
#include "stddef.h"
#include "stdint.h"
#include "linkedlist.h"
#include "hashtable.h"

#define TABLE_SIZE 10

typedef struct hashtable_entry
{
    char* key;
    void* val;
} hashtable_entry_t;

typedef struct hashtable
{
    linkedlist_t* buckets[TABLE_SIZE];
} hashtable_t;

// Dan Bernstein algorithm: http://www.cse.yorku.ca/~oz/hash.html
int get_hash(unsigned char* key, int buckets_count)
{
    unsigned long hash = 5381;
    int c;

    while (c = *key++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash%buckets_count;
}

hashtable_t* hashtable_new()
{
    hashtable_t* table = malloc(sizeof(hashtable_t));
    return table;
}

void hashtable_free(hashtable_t* table)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        linkedlist_free(table->buckets[i]);
    }

    free(table->buckets);
    free(table);
}

hashtable_entry_t* hashtable_entry_new(char* key, void* obj)
{
    hashtable_entry_t* entry = malloc(sizeof(hashtable_entry_t));
    entry->key = key;
    entry->val = obj;

    return entry;
}

HashTableResult hashtable_add(hashtable_t* table, char* key, void* obj)
{
    int bucket = get_hash(&key, TABLE_SIZE);
    if(table->buckets[bucket] == NULL)
    {
        table->buckets[bucket] = linkedlist_new();
    }

    int listcnt = linkedlist_count(table->buckets[bucket]);
    if(listcnt == 0)
    {
        hashtable_entry_t* entry = hashtable_entry_new(key, obj);
        linkedlist_add_first(table->buckets[bucket], entry);
        return SUCCESS;
    }

    hashtable_entry_t* current;
    int index = 0;
    while((current = linkedlist_get_next(table->buckets[bucket])) != NULL)
    {
        int result = strcmp(key, current->key);
        if(result == 0) 
        {
            return ALREADY_EXISTS;
        }
        else if(result < 0)
        {
            hashtable_entry_t* entry = hashtable_entry_new(key, obj);
            linkedlist_add_before(table->buckets[bucket], index, entry);
            return SUCCESS;
        }
        else if(index == (listcnt - 1)) // current is last object in linked list
        {
            hashtable_entry_t* entry = hashtable_entry_new(key, obj);
            linkedlist_add_last(table->buckets[bucket], entry);
            return SUCCESS;
        }

        index++;
    }

    return UNKNOWN_ERROR;
}

void* hashtable_get(hashtable_t* table, char* key)
{
    int bucket = get_hash(&key, TABLE_SIZE);
    if(table->buckets[bucket] == NULL)
    {
        return NULL;
    }

    hashtable_entry_t* current;
    while((current = linkedlist_get_next(table->buckets[bucket])) != NULL)
    {
        if(strcmp(key, current->key) == 0)
        {
            return current->val;
        }
    }

    return NULL;
}
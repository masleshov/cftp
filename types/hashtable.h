typedef enum HashTableResult
{
    SUCCESS = 0,
    UNKNOWN_ERROR = -1,
    ALREADY_EXISTS = -2
} HashTableResult;

typedef struct hashtable hashtable_t;

hashtable_t* hashtable_new();
HashTableResult hashtable_add(hashtable_t* table, char* key, void* obj);
void* hashtable_get(hashtable_t* table, char* key);
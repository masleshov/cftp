typedef struct linkedlist_node linkedlist_node_t;
typedef struct linkedlist linkedlist_t;

linkedlist_t* linkedlist_new();
void linkedlist_free(linkedlist_t* list);
int linkedlist_count(linkedlist_t* list);
int linkedlist_add_last(linkedlist_t* list, void* obj);
int linkedlist_add_first(linkedlist_t* list, void* obj);
int linkedlist_add_before(linkedlist_t* list, int index, void* obj);
void* linkedlist_get_next(linkedlist_t* list);
void* linkedlist_get_prev(linkedlist_t* list);
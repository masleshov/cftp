typedef struct node node_t;
typedef struct linkedlist linkedlist;

linkedlist* linked_list_new();
void linkedlist_free(linkedlist* list);
int linkedlist_count(linkedlist* list);
int linkedlist_add_last(linkedlist* list, void* obj);
int linkedlist_add_first(linkedlist* list, void* obj);
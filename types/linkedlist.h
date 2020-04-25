typedef struct node node_t;
typedef struct linkedlist linkedlist;

linkedlist* linked_list_new();
void linked_list_free(linkedlist* list);
int linked_list_count(linkedlist* list);
int linked_list_add_last(linkedlist* list, void* obj);
int linked_list_add_first(linkedlist* list, void* obj);
#include "stdlib.h"
#include "stddef.h"
#include "linkedlist.h"

typedef struct node 
{
    void*        val;
    struct node* next;
} node_t;

typedef struct linkedlist
{
    node_t* first;
    node_t* last;
    int     count;
} linkedlist;

node_t* create_node()
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->val = NULL;
    node->next = NULL;

    return node;
}

linkedlist* linked_list_new()
{
    return (linkedlist*)malloc(sizeof(linkedlist));
}

void linked_list_free(linkedlist* list)
{
    node_t* tmp;
    node_t* current = list->first;
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        free(current);
    }
    free(list);
}

int linked_list_count(linkedlist* list)
{
    return list->count;
}

int linked_list_add_last(linkedlist* list, void* obj)
{
    if(list == NULL) return -1;

    node_t* node = create_node();
    node->val = obj;
    
    if(list->count++ == 0)
    {
        list->first = node;
    }
    else
    {
        list->last->next = node;
    }
    

    list->last = node;

    return 0;
}

int linked_list_add_first(linkedlist* list, void* obj)
{
    if(list == NULL) return -1;

    node_t* node = create_node();
    node->val = obj;

    if(list->count++ == 0)
    {
        list->last = node;
    }
    else
    {
        node->next = list->first;
    }
    

    list->first = node;

    return 0;
}
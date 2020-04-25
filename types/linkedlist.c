#include "stdlib.h"
#include "stddef.h"
#include "linkedlist.h"

typedef struct linkedlist_node 
{
    void*        val;
    struct linkedlist_node* next;
    struct linkedlist_node* prev;
} linkedlist_node_t;

typedef struct linkedlist
{
    linkedlist_node_t* first;
    linkedlist_node_t* last;
    linkedlist_node_t* current;
    int              count;
} linkedlist_t;

linkedlist_node_t* create_node()
{
    linkedlist_node_t* node = (linkedlist_node_t*)malloc(sizeof(linkedlist_node_t));
    node->val = NULL;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

linkedlist_t* linkedlist_new()
{
    return (linkedlist_t*)malloc(sizeof(linkedlist_t));
}

void linkedlist_free(linkedlist_t* list)
{
    linkedlist_node_t* tmp;
    linkedlist_node_t* current = list->first;
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(list);
}

int linkedlist_count(linkedlist_t* list)
{
    return list->count;
}

int linkedlist_add_last(linkedlist_t* list, void* obj)
{
    if(list == NULL) return -1;

    linkedlist_node_t* node = create_node();
    node->val = obj;
    
    if(list->count++ == 0)
    {
        list->first = node;
    }
    else
    {
        list->last->next = node;
        node->prev = list->last;
    }
    

    list->last = node;

    return 0;
}

int linkedlist_add_first(linkedlist_t* list, void* obj)
{
    if(list == NULL) return -1;

    linkedlist_node_t* node = create_node();
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

void* linkedlist_get_next(linkedlist_t* list)
{
    if(list->count == 0) return NULL;

    if(list->current == NULL)
    {
        list->current = list->first;
    }
    else
    {
        list->current = list->current->next;
    }
    
    return list->current->val;
}

void* linkedlist_get_prev(linkedlist_t* list)
{
    if(list->count == 0) return NULL;

    if(list->current == NULL)
    {
        list->current = list->last;
    }
    else
    {
        list->current = list->current->prev;
    }

    return list->current->val;    
}
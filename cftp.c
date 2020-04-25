#include "stdio.h"
#include "stdlib.h"
#include "types/linkedlist.h"

int main()
{
    linkedlist* list = linked_list_new();
    for(int i = 0; i < 100; i++)
    {
        int res = linked_list_add_first(list, i);
        if(res == -1) return -1;
    }

    printf("count = %d\n", linked_list_count(list));

    linked_list_free(list);
    printf("list size %d\n", sizeof(list));
}
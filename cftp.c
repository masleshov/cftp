#include "stdio.h"
#include "stdlib.h"
#include "types/linkedlist.h"

int main()
{
    linkedlist* list = linkedlist_new();
    for(int i = 0; i < 100; i++)
    {
        int res = linkedlist_add_first(list, i);
        if(res == -1) return -1;
    }

    printf("count = %d\n", linkedlist_count(list));

    linkedlist_free(list);
    printf("list size %d\n", sizeof(list));
}
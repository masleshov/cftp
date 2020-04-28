#include "stdio.h"
#include "stdlib.h"
#include "types/hashtable.h"

int main()
{
    hashtable_t* table = hashtable_new();
    hashtable_add(table, "a", 10);
    int t = hashtable_get(table, "a");
    printf("t = %d\n", t);
}
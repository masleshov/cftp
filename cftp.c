#include "stdio.h"
#include "stdlib.h"
#include "types/hashtable.h"

bool compare(char key1, char key2)
{
    return key1 == key2;
}

int main()
{
    hashtable_t* table = hashtable_new();
    hashtable_add(table, 'a', 10, compare);
    int t = hashtable_get(table, 'a', compare);
    printf("t = %d\n", t);
}
#include <limits.h>

int is_prime(int number)
{
    if((number & 1) == 0) return number == 2;
    
    int i, limit = sqrt(number);
    for (i = 3; i <= limit; i += 2)
    {
        if (number % i == 0) return 0;
    }

    return 1;
}

int get_prime(int last)
{
    if(last < 2) return 2;
    if (last == 2) return 3;
    if(last == INT_MAX) return INT_MAX;

    if(last & 1)
    {
        int number = last + 2;
        return is_prime(number) ? number : get_prime(number);
    } 
    else
    {
        return get_prime(last-1);
    }

    return -1;
}
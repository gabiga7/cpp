#include "is_prime.h"
#include "iostream"

bool is_prime(int my_x)
{
    if (my_x <= 1)
        return false;
    if (my_x <= 3)
        return true;

    if (my_x % 2 == 0 || my_x % 3 == 0)
        return false;

    for (int i = 5; i * i <= my_x; i = i + 6)
        if (my_x % i == 0 || my_x % (i + 2) == 0)
            return false;
    return true;
}
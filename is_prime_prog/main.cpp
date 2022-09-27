#include <iostream>
#include "is_prime.h"

int main()
{
    int my_x;
    while (std::cin >> my_x) {
        std::cout << my_x << " is a prime: ";
        is_prime(my_x) ? std::cout << "True\n" : std::cout << "False\n";
    }
    return 0;
}
#include <iostream>
#include <map>

#include "allocator.h"


int factorial (int number)
{
    if (number)
        return number * factorial(number - 1);
    else
        return 1;
}


int main(int, char **)
{
    std::cout << "Homework 03: allocator" << std::endl;
    std::cout << "===================================\n";
    std::cout << std::endl;

    const auto size {10};
    std::map<int, int> map;


    std::cout << "std::map:" << std::endl;
    for (auto cnt {0}; cnt < size; ++cnt) {
        map.insert( std::pair<int,int>(cnt, factorial(cnt)) );
    }

    for (const auto& number : map){
        std::cout << number.first << " " << number.second << std::endl;
    }

    std::cout << "\nstd::map with MyAllocator:" << std::endl;
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>>> map_alloc;
    for (auto cnt {0}; cnt < size; ++cnt) {
        map_alloc.insert( std::pair<int,int>(cnt, factorial(cnt)) );
    }

    for (const auto& number : map_alloc){
        std::cout << number.first << " " << number.second << std::endl;
    }

	return 0;
}

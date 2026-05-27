#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> arr(5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
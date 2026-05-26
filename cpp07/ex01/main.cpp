#include "iter.hpp"
#include <iostream>

int main(){
    int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ::iter(array1, 10, funIter);
    for (int i = 0; i < 10; i++)
        std::cout << "Array[" << i << "]" << array1[i] << std::endl;

    std::string array2[10] = {"0123456789"};
    ::iter(array2, 10, funIter);
    for (int i = 0; i < 10; i++)
        std::cout << "Array[" << i << "]" << array2[i] << std::endl; 
}
#include "whatever.hpp"
#include "iostream"

int main(){
    int number1 = 10;
    int number2 = 20;

    swap(number1, number2);
    std::cout << "number1: " << number1 << std::endl << "number2: " << number2 << std::endl;
    std::cout << "Min: " << min(number1, number2) << std::endl;
    std::cout << "Max: " << max(number1, number2) << std::endl;

}
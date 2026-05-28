#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec;
    for (int i = 0; i < 10; i++){
        vec.push_back(i);
    }
    try{
        easyFind(&vec, 5);
        easyFind(&vec, 15);
    }
    catch (std::runtime_error& e){
        std::cout << e.what() << std::endl;
    }
}
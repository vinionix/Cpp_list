#include "Span.hpp"

int main()
{
    Span sp = Span(10000);

    int arr[10000];
    for (int i = 0; i < 10000; i++){
        arr[i] = std::rand();
    } 
    try{
        sp.addMultipleNumbers(&arr[0], &arr[10000]);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
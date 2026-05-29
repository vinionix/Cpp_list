#pragma once

# include <iostream>
# include <cstdlib>

class Span{
    private:
        unsigned int N;
        unsigned int currentSize;
        int* array;
    public:
        Span(unsigned int n);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        void printSpan(Span* span);
        unsigned int getN( void );
        unsigned int getCurrentSize( void );
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void organizeArray(Span* span);
        void addMultipleNumbers(int* begin, int* end);
};
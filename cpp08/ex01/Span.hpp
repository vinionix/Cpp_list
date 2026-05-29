#pragma once

# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>

class Span{
    private:
        unsigned int N;
        unsigned int currentSize;
        std::vector<int> array;
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
        void addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
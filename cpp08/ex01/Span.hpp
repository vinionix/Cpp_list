#pragma once

# include <iostream>

class Span{
    private:
        unsigned int N;
        int* array;
    public:
        Span(unsigned int n);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
};
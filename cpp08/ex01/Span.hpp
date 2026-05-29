#pragma once

# include <iostream>

class Span{
    private:
        unsigned int N;
        unsigned int currentSize;
        int* array;
    public:
        Span(unsigned int n);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        const Span& getArray( const int pos ) const;
        unsigned int getN( void );
        unsigned int getCurrentSize( void );
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void organizeArray(Span* span);
        void addMultipleNumbers(int* begin, int* end);
};
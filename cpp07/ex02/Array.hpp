#pragma once

#include <iostream>

template <class T>
class Array {
    private:
        T* array;
        unsigned int length;
    public:
        Array<T>();
        Array<T>(unsigned int n);
        Array<T>(const Array<T>& copy);
        ~Array<T>();
        Array<T>& operator=(const Array<T>& copy);
        T& operator[](unsigned int index);
        unsigned int size() const;
};

# include "Array.tpp"
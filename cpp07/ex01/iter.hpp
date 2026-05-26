#pragma once

template <typename T>
void funIter(T& elementArray){
    elementArray = 65;
}

template <typename T>
void iter(T* array, const int length, void (*fun)(T&)){
    for (int i = 0; i < length; i++)
        fun(array[i]);
}

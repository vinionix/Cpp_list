#pragma once

template <typename T>
void    swap(T& param1, T& param2){
    T temp = param2;
    param2 = param1;   
    param1 = temp;
}

template <typename T>
const T&       min(T& param1, T& param2){
    return (param2 <= param1 ? param2 : param1);
}

template <typename T>
const T&       max(T& param1, T& param2){
    return (param2 >= param1 ? param2 : param1);
}
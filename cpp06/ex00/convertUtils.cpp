#include "convertUtils.hpp"

int skipSpace(char* str){
    int i = 0; 

    while (str[i] == ' ' && str[i] != '\0')
        i++;
    return (i);
}

int countSignalFun(char* str, int* i){
    int countSignal = 0;
    while (str[*i] != '\0' && (str[*i] == '+' || str[*i] == '-'))
    {
        countSignal++;
        (*i)++;
    } 
    return (countSignal);
}

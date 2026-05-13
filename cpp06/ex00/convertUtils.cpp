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

bool verifyPoint(char* str){
    int countP = 0;
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == '.')
            countP++;
        if (countP > 1 || (str[i] == '.' && (str[i + 1] < '0' || str[i + 1] > '9')))
            return (false);
        i++;
    }
    return (true);
}

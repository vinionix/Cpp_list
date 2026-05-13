#include "ConvertDouble.hpp"

ConvertDouble::ConvertDouble(){}

ConvertDouble::~ConvertDouble(){}

bool ConvertDouble::isDoubleError( void ){
    return (false);
}

bool ConvertDouble::isDouble(char* str){
    int i = skipSpace(str);
    int countSignal;

    countSignal = countSignalFun(str, &i);
    if (countSignal > 1 || str[i] == '\0')
        return (isDoubleError());
    while (str[i] != '\0' && str[i] != '.'){
        if (str[i] < '0' || str[i] > '9')
           return (isDoubleError());
        i++;
    }
    if (!verifyPoint(str))
        return (isDoubleError());
    return (true);
}

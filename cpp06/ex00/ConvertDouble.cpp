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

void ConvertDouble::printConvertedDouble(double converted){
    if (converted > std::numeric_limits<double>::max() || converted < -std::numeric_limits<double>::max())
        std::cout << "Double: Impossible" << std::endl;
    else
        std::cout << "Double: " << converted << std::endl;
}

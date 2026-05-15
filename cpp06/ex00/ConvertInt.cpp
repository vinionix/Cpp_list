#include "ConvertInt.hpp"

ConvertInt::ConvertInt(){}

ConvertInt::~ConvertInt(){}

bool ConvertInt::isIntError( void ){
    return (false);
}

bool ConvertInt::isInt(char* str){
    int i = skipSpace(str);
    int countSignal;

    countSignal = countSignalFun(str, &i);
    if (countSignal > 1 || str[i] == '\0')
        return (isIntError());
    while (str[i] != '\0'){
        if (str[i] < '0' || str[i] > '9')
            return (isIntError());
        i++;
    }
    return (true);
}

void ConvertInt::printConvetedInt(double converted){
    if (converted > std::numeric_limits<int>::max() || converted < std::numeric_limits<int>::min())
        std::cout << "Int: Impossible" << std::endl;
    else
        std::cout << "Int: "<< static_cast<int>(converted) << std::endl;
}

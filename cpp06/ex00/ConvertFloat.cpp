#include "ConvertFloat.hpp"

ConvertFloat::ConvertFloat(){}

ConvertFloat::~ConvertFloat(){}

bool ConvertFloat::isFloatError( void ){
    return (false);
}
bool verifyLetters(char* str){
    int countF = 0;
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == 'f')
            countF++;
        if (countF > 1 || (str[i] == 'f' && str[i + 1] != '\0'))
            return (false);
        i++;
    } 
    return (true);
}

bool ConvertFloat::isFloat(char* str){
    int i = skipSpace(str);
    int countSignal;

    countSignal = countSignalFun(str, &i);

    if (countSignal > 1 || str[i] == '\0')
        return (isFloatError());
    while (str[i] != '\0' && str[i] != '.' && str[i] != 'f'){
        if (str[i] < '0' || str[i] > '9')
           return (isFloatError());
        i++;
    }
    if (!verifyPoint(str) || !verifyLetters(str))
        return (isFloatError());
    while (str[i] != '\0'){
        if ((str[i + 1] == '\0' && str[i] != 'f'))
            return (isFloatError());
        i++;
    }
    return (true);
}

void ConvertFloat::printConvertedFloat(double converted){
    if (converted > std::numeric_limits<float>::max() || converted < -std::numeric_limits<float>::max())
        std::cout << "Float: Impossible" << std::endl;
    else
        std::cout << "Float: " << static_cast<float>(converted) << "f" << std::endl;
}

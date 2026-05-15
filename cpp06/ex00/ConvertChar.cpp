#include "ConvertChar.hpp"

ConvertChar::ConvertChar(){}

ConvertChar::~ConvertChar(){}

bool ConvertChar::isCharError( void ){
    return (false);
}

static int ft_strlen(char* str){
    int i = 0;

    while (str[i] != 0){
        i++;
    }
    return (i);
}

bool ConvertChar::isChar(char* str){
    if (ft_strlen(str) != 1 || (str[0] >= '0' && str[0] <= '9'))
        return (isCharError());
    return (true);
}

void ConvertChar::printConvertChar(double converted){
    if (static_cast<long>(converted) >= 32 && static_cast<long>(converted) <= 126)
        std::cout << "Char: " << static_cast<char>(converted) << std::endl;
    else
        std::cout << "Char: Impossible" << std::endl;
}

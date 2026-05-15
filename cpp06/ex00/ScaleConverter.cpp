#include "ScaleConverter.hpp"

ScaleConverter::ScaleConverter(){}

ScaleConverter::~ScaleConverter(){}

static bool specialCasesConvert(char* str){
    char pseudoLiterary[6][6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    int i = 0;

    while (i < 6){
        if (std::strcmp(str, pseudoLiterary[i]) == 0)
            break ;
        i++;
    }
    if (i == 6)
        return (false);
    std::cout << "Char: Impossible" << std::endl;
    std::cout << "Int: Impossible" << std::endl;
    if (i == NEG_INFF || i == NEG_INF) {
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else if (i == POS_INFF || i == POS_INF){
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else {
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    return (true);
}

static void printConveted(char* str){
    double converted = atof(str);

    std::cout << std::fixed << std::setprecision(1);
    ConvertChar::printConvertChar(converted);
    ConvertInt::printConvetedInt(converted);
    ConvertFloat::printConvertedFloat(converted);
    ConvertDouble::printConvertedDouble(converted);
}
void ScaleConverter::convert(char* str){
    if (str == NULL)
        return ;
    if (specialCasesConvert(str) == true)
        return ;
    if (!ConvertChar::isChar(str) && !ConvertInt::isInt(str) && !ConvertFloat::isFloat(str) && !ConvertDouble::isDouble(str)){
        std::cout << "Char: Impossible" << std::endl;
        std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: Impossible" << std::endl;
        std::cout << "Double: Impossible" << std::endl;
        return ;
    }
    printConveted(str);
}

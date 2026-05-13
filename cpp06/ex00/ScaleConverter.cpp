#include "ScaleConverter.hpp"

ScaleConverter::ScaleConverter(){}

ScaleConverter::~ScaleConverter(){}

enum SpecialCase{
    NEG_INFF = 0, 
    POS_INFF = 1, 
    NANF = 2, 
    NEG_INF = 3, 
    POS_INF = 4, 
    NAN = 5
};

static void specialCasesConvert(SpecialCase sc){
    std::cout << "Char: Impossible" << std::endl;
    std::cout << "Int: Impossible" << std::endl;
    if (sc == NEG_INFF || sc == NEG_INF) {
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else if (sc == POS_INFF || sc == POS_INF){
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else {
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
}

void ScaleConverter::convert(char* str){
    char pseudoLiterary[6][6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    if (str == NULL)
        return ;
    for (int i = 0; i < 6; i++){
        if (std::strcmp(str, pseudoLiterary[i]) == 0)
            specialCasesConvert(static_cast<SpecialCase>(i));
    }
    if (ConvertInt::isInt(str)){
        int converted = std::atoi(str);
        std::cout << "Int: " << converted << std::endl;
    }
    if (ConvertFloat::isFloat(str)){
        int converted = std::atof(str);
        std::cout << "Float: " << converted << std::endl;
    }
}

#include "ScaleConverter.hpp"

ScaleConverter::ScaleConverter(){}

ScaleConverter::~ScaleConverter(){}

void ScaleConverter::convert(char* str){
    char pseudoLiterary[6][6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    
    for (int i = 0; str[i] != '\0'; i++){
        if (std::strcmp(str, pseudoLiterary[i]) == 0)
        {}
    }
}
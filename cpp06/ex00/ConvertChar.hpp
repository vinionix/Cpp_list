#pragma once
# include "convertUtils.hpp"
# include <iostream>

class ConvertChar{

    private:
        ConvertChar();
        ~ConvertChar();
    public:
        static bool isCharError( void );
        static bool isChar(char* str);
        static void printConvertChar(double converted);
};

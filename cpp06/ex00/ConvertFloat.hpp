#pragma once
# include "convertUtils.hpp"
# include <iostream>
# include <limits>

class ConvertFloat{

    private:
        ConvertFloat();
        ~ConvertFloat();
    public:
        static bool isFloatError( void );
        static bool isFloat(char* str);
        static void printConvertedFloat(double converted);
};

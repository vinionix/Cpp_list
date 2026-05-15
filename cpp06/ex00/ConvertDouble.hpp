#pragma once
# include "convertUtils.hpp"
# include <iostream>
# include <limits>

class ConvertDouble{

    private:
        ConvertDouble();
        ~ConvertDouble();
    public:
        static bool isDoubleError( void );
        static bool isDouble(char* str);
        static void printConvertedDouble(double converted);
};

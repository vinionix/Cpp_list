#pragma once
# include "convertUtils.hpp"
# include <iostream>
# include <limits>

class ConvertInt{

    private:
        ConvertInt();
        ~ConvertInt();
    public:
        static bool isIntError( void );
        static bool isInt(char* str);
        static void printConvetedInt(double converted);
};

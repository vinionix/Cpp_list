#pragma once
# include "convertUtils.hpp"
# include <iostream>

class ConvertFloat{

    private:
        ConvertFloat();
        ~ConvertFloat();
    public:
        static bool isFloatError( void );
        static bool isFloat(char* str);
};

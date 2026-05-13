#pragma once
# include "convertUtils.hpp"
# include <iostream>

class ConvertDouble{

    private:
        ConvertDouble();
        ~ConvertDouble();
    public:
        static bool isDoubleError( void );
        static bool isDouble(char* str);
};

#pragma once
# include "convertUtils.hpp"
# include <iostream>

class ConvertInt{

    private:
        ConvertInt();
        ~ConvertInt();
    public:
        static bool isIntError( void );
        static bool isInt(char* str);
};

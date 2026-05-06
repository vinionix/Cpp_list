#pragma once

# include <iostream>
# include <stdlib.h>
# include <cstring>

class ScaleConverter{
    private:
        ScaleConverter();
        ~ScaleConverter();
    public:
        static void convert(char* str);
};
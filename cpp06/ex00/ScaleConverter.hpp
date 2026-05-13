#pragma once

# include <iostream>
# include <stdlib.h>
# include <cstring>
# include "ConvertInt.hpp"
# include "ConvertFloat.hpp"
# include "ConvertDouble.hpp"

class ScaleConverter{
    private:
        ScaleConverter();
        ~ScaleConverter();
    public:
        static void convert(char* str);
};

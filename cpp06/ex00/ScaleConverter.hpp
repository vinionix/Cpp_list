#pragma once

# include <iostream>
# include <stdlib.h>
# include <cstring>
# include "ConvertInt.hpp"
# include "ConvertFloat.hpp"
# include "ConvertDouble.hpp"
# include "ConvertChar.hpp"
# include <iomanip>
# include <cstdlib>
# define NEG_INFF 0 
# define POS_INFF 1     
# define NANF 2
# define NEG_INF 3 
# define POS_INF 4 
# define NAN 5

class ScaleConverter{
    private:
        ScaleConverter();
        ~ScaleConverter();
    public:
        static void convert(char* str);
};

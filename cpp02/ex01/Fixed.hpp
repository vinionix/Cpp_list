#pragma once
# include <iostream>
# include <cmath>

class Fixed {
    private:
        int                 _rawInt;
        static const int    _fractionalBits = 8;
    public:

        //Builder:
        Fixed( void );
        Fixed(const Fixed& copy);
        Fixed(const int rawInt);
        Fixed(const float rawFloat);

        //Operator overload:
        Fixed& operator=(const Fixed& other);
        
        //Destroyer:
        ~Fixed( void );

        //Get and Set:
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        //Converters:
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

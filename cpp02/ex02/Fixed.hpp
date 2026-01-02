#pragma once
# include <iostream>
# include <cmath>
# include <climits>

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
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++( int );
        Fixed operator--( int);
        
        //Destroyer:
        ~Fixed( void );

        //Get and Set:
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        //Converters:
        float toFloat( void ) const;
        int toInt( void ) const;

		//mim and max:
		static Fixed& max(Fixed& num1, Fixed& num2);
		static const Fixed& max(const Fixed& num1, const Fixed& num2);
        static Fixed& min(Fixed& num1, Fixed& num2);
		static const Fixed& min(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

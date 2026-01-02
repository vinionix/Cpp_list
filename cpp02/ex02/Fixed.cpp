#include "Fixed.hpp" 

//Builder:

Fixed::Fixed() : _rawInt(0){}

Fixed::Fixed(const Fixed& copy) : _rawInt(copy._rawInt) {}

Fixed::Fixed(const int rawInt) : _rawInt(rawInt * (1 << _fractionalBits)){}

Fixed::Fixed(const float rawFloat) : _rawInt(roundf(rawFloat * (1 << _fractionalBits))){}

/**************/

//Operator overload:

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other) 
		this->_rawInt = other._rawInt; 
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value){
	out << value.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& other) const { return (this->_rawInt > other._rawInt); }

bool Fixed::operator<(const Fixed& other) const { return (this->_rawInt < other._rawInt); }

bool Fixed::operator>=(const Fixed& other) const { return (this->_rawInt >= other._rawInt); }

bool Fixed::operator<=(const Fixed& other) const { return (this->_rawInt <= other._rawInt); }

bool Fixed::operator==(const Fixed& other) const { return (this->_rawInt == other._rawInt); }

bool Fixed::operator!=(const Fixed& other) const { return (this->_rawInt != other._rawInt); }

Fixed Fixed::operator+(const Fixed& other) const{
	Fixed result;
	long	resultRaw = this->_rawInt + other._rawInt;
	result._rawInt = resultRaw;
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const{
	Fixed result;
	long	resultRaw = this->_rawInt - other._rawInt;
	result._rawInt = resultRaw;
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const{
	Fixed result;
	long	resultRaw = ((long)this->_rawInt * (long)other._rawInt) >> this->_fractionalBits;
	result._rawInt = resultRaw;
	return (result); 
}

Fixed Fixed::operator/(const Fixed& other) const{
	Fixed result;
	if (other._rawInt == 0)
	{
		result._rawInt = 0;
		return (result);
	}
	long	resultRaw = ((long)this->_rawInt << this->_fractionalBits) / other._rawInt;
	result._rawInt = resultRaw;
	return (result); 
}

Fixed& Fixed::operator++(){
	this->_rawInt += 1;
	return(*this);
}

Fixed& Fixed::operator--(){
	this->_rawInt -= 1;
	return(*this);
}

Fixed Fixed::operator++( int ){
	Fixed temp = *this;
	this->_rawInt += 1;
	return (temp);
}

Fixed Fixed::operator--( int ){
	Fixed temp = *this;
	this->_rawInt -= 1;
	return (temp);
}

/**************/

//Destroyer:

Fixed::~Fixed( void ){}

/**************/

//Get and Set:

int Fixed::getRawBits( void ) const { return _rawInt; }

void Fixed::setRawBits( int const raw ) { _rawInt = raw; }

/**************/

//Converters:

float Fixed::toFloat( void ) const { return ((float)_rawInt / (1 << _fractionalBits)); }

int Fixed::toInt( void ) const { return (_rawInt / (1 << _fractionalBits)); }

/**************/

//Min and Max:

Fixed& Fixed::max(Fixed& num1, Fixed& num2) { return (num1 > num2 ? num1 : num2); }

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) { return (num1 > num2 ? num1 : num2); }

Fixed& Fixed::min(Fixed& num1, Fixed& num2) { return (num1 < num2 ? num1 : num2); }

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) { return (num1 < num2 ? num1 : num2); }

/**************/
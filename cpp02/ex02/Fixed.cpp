#include "Fixed.hpp" 

//Builder:

Fixed::Fixed() : _rawInt(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy){
	this->_rawInt = copy._rawInt;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int rawInt) : _rawInt(rawInt * (1 << _fractionalBits)){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float rawFloat) : _rawInt(roundf(rawFloat * (1 << _fractionalBits))){
	std::cout << "Float constructor called" << std::endl;
}

/**************/

//Operator overload:

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other) 
		this->_rawInt = other._rawInt; 
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value){
	out << value.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& other) const{
	return (this->_rawInt > other._rawInt);
}

bool Fixed::operator<(const Fixed& other) const{
	return (this->_rawInt < other._rawInt);
}

bool Fixed::operator>=(const Fixed& other) const{
	return (this->_rawInt >= other._rawInt);
}

bool Fixed::operator<=(const Fixed& other) const{
	return (this->_rawInt <= other._rawInt);
}

bool Fixed::operator==(const Fixed& other) const{
	return (this->_rawInt == other._rawInt);
}

bool Fixed::operator!=(const Fixed& other) const{
	return (this->_rawInt != other._rawInt);
}

Fixed Fixed::operator+(const Fixed& other) const{
	Fixed result;
	result._rawInt = this->_rawInt + other._rawInt;
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const{
	Fixed result;
	result._rawInt = this->_rawInt - other._rawInt;
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const{
	Fixed result;
	long	resultRaw = ((long)this->_rawInt * (long)other._rawInt) >> this->_fractionalBits;
	if (resultRaw > INT_MAX || resultRaw < INT_MAX)
	{
		result._rawInt = 0;
		return (result);
	}
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
	if (resultRaw > INT_MAX || resultRaw < INT_MAX)
	{
		result._rawInt = 0;
		return (result);
	}
	result._rawInt = resultRaw;
	return (result); 
}

Fixed& Fixed::operator++(){
	
}

Fixed& Fixed::operator--(){
	
}

Fixed& Fixed::operator++( int ){
	
}

Fixed& Fixed::operator--( int ){

}

/**************/

//Destroyer:

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

/**************/

//Get and Set:

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawInt;
}

void Fixed::setRawBits( int const raw ){
	_rawInt = raw;
}

/**************/

//Converters:

float Fixed::toFloat( void ) const{
	return ((float)_rawInt / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const{
	return (_rawInt / (1 << _fractionalBits));
}

/**************/
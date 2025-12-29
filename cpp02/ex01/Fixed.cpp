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
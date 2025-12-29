#include "Fixed.hpp" 

Fixed::Fixed() : _rawInt(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy){
	this->_rawInt = copy.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other) 
		this->_rawInt = other._rawInt; 
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawInt;
}

void Fixed::setRawBits( int const raw ){
	_rawInt = raw;
}
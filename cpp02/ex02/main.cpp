#include "Fixed.hpp"
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( Fixed( 5.05f ) / Fixed( 2 ) );
	
	std::cout << std::endl << "Defalt builder: " << a << std::endl;
	std::cout << "Increment operator/pre: " << ++a << std::endl;
	std::cout << "Verify: " << a << std::endl;
	std::cout << "Increment operator/pos: " << a++ << std::endl;
	std::cout << "Verify: " << a  << std::endl << std::endl;

	std::cout << "Builder: " << c << std::endl;
	std::cout << "Decrease operator/pre: " << --c << std::endl;
	std::cout << "Verify: " << c << std::endl;
	std::cout << "Decrease operator/pos: " << c-- << std::endl;
	std::cout << "Verify: " << c  << std::endl << std::endl << std::endl;
	
	std::cout << "Mult: " << b << std::endl;
	std::cout << "Div: " << c << std::endl;
	std::cout << "Sum: " << a + b + c << std::endl;
	std::cout << "Subtraction: " << b - c - a << std::endl << std::endl;

	std::cout << "Max number: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min number: " << Fixed::min( a, b ) << std::endl << std::endl;
	

	 
	c = a;
	std::cout << "Copy operator: " << c << std::endl;
	if (a == c)
		std::cout << "Comparison of equality: " << "true" << std::endl;
	if (b != c)
		std::cout << "Difference comparison: " << "true" << std::endl;
	if (b >= c)
		std::cout << "Less than or equal to comparison: " << "true" << std::endl;
	if (c <= b)
		std::cout << "greater than or equal to comparison: " << "true" << std::endl << std::endl;

	std::cout << "To float : " << b.toFloat() << std::endl;
	std::cout << "To int: " << b.toInt() << std::endl;
	return 0;
}
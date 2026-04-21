#include "Bureaucrat.hpp"

int main( void ){
	try {
		Bureaucrat Vinicius("Vinicius", 1);
		std::cout << Vinicius;
		Vinicius.decrement();
		std::cout << Vinicius;
		Vinicius.increase();
		std::cout << Vinicius;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat Adyvan("Adyvan", 0);
		std::cout << Adyvan;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat Luiza("Luiza", 151);
		std::cout << Luiza;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

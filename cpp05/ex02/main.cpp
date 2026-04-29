#include "Bureaucrat.hpp"

int main( void ){
	try {
		AForm textForm("TextForm", 3, 4);
		Bureaucrat Vinicius("Vinicius", 1);
		Vinicius.signForm(textForm);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat Adyvan("Adyvan", 5);
		AForm textForm2("TextForm2", 1, 1);
		Adyvan.signForm(textForm2);	
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

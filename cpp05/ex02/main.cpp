#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ){
	try {
		ShrubberyCreationForm textForm("TextForm");
		Bureaucrat Vinicius("Vinicius", 137);
		Vinicius.signForm(textForm);
		Vinicius.executeForm(textForm);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		RobotomyRequestForm textForm2("TextForm2");
		Bureaucrat Adyvan("Adyvan", 45);
		Adyvan.signForm(textForm2);
		Adyvan.executeForm(textForm2);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		PresidentialPardonForm textForm3("TextForm3");
		Bureaucrat Luiza("Luiza", 5);
		Luiza.signForm(textForm3);
		Luiza.executeForm(textForm3);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

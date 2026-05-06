#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main( void ){
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat Vini("Vini", 1);
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		try{
			Vini.signForm(*rrf);
			Vini.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

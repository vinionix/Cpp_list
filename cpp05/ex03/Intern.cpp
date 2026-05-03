#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm* shrubberyFun(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm* robotomyFun(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm* presidentialfun(std::string target) {
    return (new PresidentialPardonForm(target));
}

const char* Intern::FormErrorException::what() const throw(){
	return ("Grade too high!");
}

AForm* Intern::makeForm(std::string formName, std::string targetName){
    char seachForms[3][26] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* (*form[3])(const std::string target) = {
        &shrubberyFun,
        &robotomyFun,
        &presidentialfun
    };

    for (int i = 0; i < 3; i++){
        if (strcmp(seachForms[i], formName.c_str())){
            return (form[i](targetName));
        }
    }
    throw FormErrorException();
}

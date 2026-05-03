#pragma once

# include <iostream>
# include <cstring>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        AForm* makeForm(std::string formName, std::string targetName);
        
        class FormErrorException : public std::exception{
                public:
                    virtual const char* what() const throw();
        };
};

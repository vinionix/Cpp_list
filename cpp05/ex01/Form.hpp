#pragma once

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form{
    
    private:
        const std::string   _name;
        bool                _signed;
        const int           _requiredSignGrade;
        const int           _requiredExecGrade;
    
    public:
        Form(const std::string name, int requiredSignGrade, int requiredExecGrade);
        Form(const Form& copy);
        Form&               operator=(const Form& copy);
        std::string         getName( void );
        bool                getSigned( void );
        int                 getRequiredSignGrade( void );
        int                 getRequiredExecGrade( void );
        void                beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        ~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

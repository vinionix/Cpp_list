#pragma once

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm{
    
    private:
        const std::string   _name;
        bool                _signed;
        const int           _requiredSignGrade;
        const int           _requiredExecGrade;
    
    public:
        AForm(const std::string name, int requiredSignGrade, int requiredExecGrade);
        AForm(const AForm& copy);
        AForm&              operator=(const AForm& copy);
        std::string         getName( void ) const;
        bool                getSigned( void ) const;
        int                 getRequiredSignGrade( void ) const;
        int                 getRequiredExecGrade( void ) const;
        void                beSigned(const Bureaucrat& bureaucrat);
        virtual void        execute(Bureaucrat const& executor) const = 0;

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class UnsignedForm : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        virtual ~AForm();
};
std::ostream& operator<<(std::ostream& os, AForm& obj);

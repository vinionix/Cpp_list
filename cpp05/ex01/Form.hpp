#pragma once
# include <iostream>

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
        std::string         getName();
        bool                getSigned();
        int           getRequiredSignGrade();
        int           getRequiredExecGrade();
        
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
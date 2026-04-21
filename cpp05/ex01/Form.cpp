#include "Form.hpp"

Form::Form(const std::string name, int requiredSignGrade, int requiredExecGrade) : _name(name), _signed(0), _requiredSignGrade(requiredSignGrade), _requiredExecGrade(requiredExecGrade){}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _requiredSignGrade(copy._requiredSignGrade),_requiredExecGrade(copy._requiredExecGrade){}

Form& Form::operator=(const Form& copy){
    if (this != &copy){
        this->_signed = copy._signed;
    }
    return (*this);
}

std::string   Form::getName(){ return (_name); }

bool    Form::getSigned(){ return(_signed); }

int     Form::getRequiredSignGrade(){ return (_requiredSignGrade); }

int     Form::getRequiredExecGrade(){ return (_requiredExecGrade); }

void    Form::beSigned(const Bureaucrat& bureaucrat){
        if (bureaucrat.getGrade() > this->getRequiredSignGrade())
        {
            std::cout << bureaucrat << "Cannot sign form You cannot sign the " << *this << " because you are not eligible to do so." << std::endl;
            throw Form::GradeTooLowException();
        }
        this->_signed = 1; 
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Grade too Low!");
}



Form::~Form(){}

std::ostream& operator<<(std::ostream& os, const Form& obj){
    Form temp(obj);
    std::cout << "Form name: " << temp.getName() << std::endl << "Signed: " << temp.getSigned() << std::endl
                << "Required grade to sign: " << temp.getRequiredSignGrade() << std::endl << "Required grade to exec: "
                << temp.getRequiredExecGrade();
    return (os);
}
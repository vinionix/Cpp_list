#include "AForm.hpp"

AForm::AForm(const std::string name, int requiredSignGrade, int requiredExecGrade) : _name(name), _signed(0), _requiredSignGrade(requiredSignGrade), _requiredExecGrade(requiredExecGrade){}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _requiredSignGrade(copy._requiredSignGrade),_requiredExecGrade(copy._requiredExecGrade){}

AForm& AForm::operator=(const AForm& copy){
    if (this != &copy){
        this->_signed = copy._signed;
    }
    return (*this);
}

std::string   AForm::getName(){ return (_name); }

bool    AForm::getSigned(){ return(_signed); }

int     AForm::getRequiredSignGrade(){ return (_requiredSignGrade); }

int     AForm::getRequiredExecGrade(){ return (_requiredExecGrade); }

void    AForm::beSigned(const Bureaucrat& bureaucrat){
        if (bureaucrat.getGrade() > this->getRequiredSignGrade())
        {
            std::cout << bureaucrat << "Cannot sign form You cannot sign the " << *this << " because you are not eligible to do so." << std::endl;
            throw AForm::GradeTooLowException();
        }
        this->_signed = 1; 
}

std::ostream& operator<<(std::ostream& os, AForm& obj){
    std::cout << "AForm name: " << obj.getName() << std::endl << "Signed: " << obj.getSigned() << std::endl
                << "Required grade to sign: " << obj.getRequiredSignGrade() << std::endl << "Required grade to exec: "
                << obj.getRequiredExecGrade();
    return (os);
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("Grade too Low!");
}

AForm::~AForm(){}

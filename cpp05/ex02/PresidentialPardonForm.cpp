#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy){}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const{
    if (this->getSigned() == 1 && executor.getGrade() > this->getRequiredExecGrade())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == 0)
        throw UnsignedForm();
    std::cout << this->getName() << " was pardoned by Zaphod Beeblebrox." << std::endl;
    std::cout << executor.getName() << " exec " << this->getName() << std::endl << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    this->AForm::operator=(copy);
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

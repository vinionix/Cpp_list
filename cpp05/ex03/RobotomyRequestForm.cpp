#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy){}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const{
    if (this->getSigned() == 1 && executor.getGrade() > this->getRequiredExecGrade())
        throw GradeTooLowException();
    else if (this->getSigned() == 0)
        throw UnsignedForm();
    std::cout << "Vrrrrrr" << std::endl;
    std::cout << "Vrrrrrr" << std::endl;
    std::cout << "Vrrrrrr" << std::endl;
    std::cout << "Vrrrrrr" << std::endl;
    std::cout << "The " << this->getName() << " was robotized." << std::endl << std::endl;
    std::cout << executor.getName() << " exec " << this->getName() << std::endl << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    this->AForm::operator=(copy);
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

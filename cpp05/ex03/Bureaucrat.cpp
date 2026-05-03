#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade){
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
	if (this != &copy){
		this->_grade = copy._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName( void ) const{
	return(this->_name);
}

int Bureaucrat::getGrade( void ) const{
	return (this->_grade);
}

void Bureaucrat::increase(){
	if (this->_grade >= 150)
		return;
	this->_grade++;
}

void Bureaucrat::decrement(){
	if (this->_grade <= 1)
		return;
	this->_grade--;
}

void Bureaucrat::signForm( AForm& form ){
	form.beSigned((*this));
	std::cout << *this << "Signed" << form << std::endl << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) const{
	form.execute((*this));
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too low!");
}

Bureaucrat::~Bureaucrat(){}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
	os << obj.getName() << "," << " bureaucrat with grade " << obj.getGrade() << "." << std::endl;
	return (os);
}

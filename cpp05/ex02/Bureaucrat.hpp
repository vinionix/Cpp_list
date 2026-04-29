#pragma once

# include <iostream>
# include "AForm.hpp"

class AForm;
class Bureaucrat{
	private:
		const std::string	_name;
		int 				_grade;
	public:
		Bureaucrat(const std::string &name, const int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		std::string getName( void ) const;
		int getGrade( void ) const;
		void increase( void );
		void decrement( void );
		void signForm( AForm& form );
		
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

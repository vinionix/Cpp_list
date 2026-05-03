#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        ~RobotomyRequestForm();
        void    execute(Bureaucrat const& executor) const;
};
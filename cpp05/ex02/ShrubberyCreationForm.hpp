#pragma once

# include "AForm.hpp"
# include <fstream>
# include <cstring>

class ShrubberyCreationForm : public AForm{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();
        void    execute(Bureaucrat const& executor) const;
};
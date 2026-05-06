#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy){}

char* join_strings(const char* s1, const char* s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || !s2)
		return (0);
	len1 = std::strlen(s1);
	len2 = std::strlen(s2);
	result = new char[len1 + len2 + 1];
	std::strcpy(result, s1);
	std::strcat(result, s2);
	return (result);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
    if (this->getSigned() == 1 && executor.getGrade() > this->getRequiredExecGrade())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == 0)
        throw UnsignedForm();
    char* temp = join_strings(this->getName().c_str(), "_shrubbery");
    std::ofstream   file_shrubbery(temp);
    std::string     asciiTree = 
        "       ^\n"
        "      / \\\n"
        "     /   \\\n"
        "    /_____\\\n"
        "     /   \\\n"
        "    /     \\\n"
        "   /_______\\\n"
        "    /     \\\n"
        "   /       \\\n"
        "  /_________\\\n"
        "\n"
        "      | |\n"
        "      | |\n";
    if (file_shrubbery.is_open())
    {
        file_shrubbery << asciiTree << asciiTree << std::endl;
    }
    file_shrubbery.close();
    if (temp)
        delete[] temp;
    std::cout << executor.getName() << " exec " << this->getName() << std::endl << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    this->AForm::operator=(copy);
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

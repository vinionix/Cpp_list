#include "PhoneBook.hpp"

std::string skip_spaces(const std::string& str)
{
	size_t i = 0;
	while (i < str.size())
    {
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return str;
		i++;
	}
	return "";
}

PhoneBook::PhoneBook() : index(0), added_contacts(0)
{}

void print_table(std::string str)
{
    if (str.length() > 10)
        {
            for (int i = 0; i < 9; i++)
                std::cout << str[i];
            std::cout << '.';
            std::cout << "|";
        }
        else
        {
            int i = str.length();
            while (i < 10)
            {
                std::cout << ' ';
                i++;
            }
            for (int i = 0; i < int(str.length()); i++)
                std::cout << str[i];
            std::cout << "|";
        }
}

void PhoneBook::search()
{
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "| " << "     Index" << "|" <<"     FName" << "|" << "     SName" << "|" << "   Surname" << "|" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    for (int i = 0; i < added_contacts; i++)
    {
        std::cout << "|" << "          " << i + 1 << "|";
        print_table(contact[i].get_first_name());
        print_table(contact[i].get_second_name());
        print_table(contact[i].get_surname());
        std::cout << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
    }
    std::cout << "Which contact do you want to choose? Choose a number!" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    int number = 0;
    try 
    {
        std::stringstream ss(input);
        ss >> number;
    } 
    catch (std::invalid_argument&)
    {
        std::cout << "Error: Invalid arg!" << std::endl;
        return ;
    }
    catch (std::out_of_range&)
    {
        std::cout << "Error: Number out limits int!" << std::endl;
        return ;
    }
    if (number > PhoneBook::added_contacts || number <= 0)
    {
        std::cout << "This index does not exist in the list!" << std::endl;
        return ;
    }
    std::cout << "First Name : " << contact[number - 1].get_first_name() << std::endl;
    std::cout << "Second Name : " << contact[number - 1].get_second_name() << std::endl;
    std::cout << "Surname : " << contact[number - 1].get_surname() << std::endl;
    std::cout << "Darkest Secret: " << contact[number - 1].get_darkest_secret() << std::endl;
    std::cout << "Phone Number: " << contact[number - 1].get_phone_number() << std::endl;
}

void PhoneBook::add()
{
    std::string input;

    if (added_contacts < 8)
        added_contacts++;
    if (index > 7)
        index = 0;
    do
    {
        std::cout << "First Name: " << std::endl;
        if (!std::getline(std::cin, input))
            exit(1);
        contact[index].get_first_name() = skip_spaces(input);
    }
    while (contact[index].get_first_name().empty());
    do
    {
        std::cout << "Second Name: " << std::endl;
        if(!std::getline(std::cin, input))
            exit(1);
        contact[index].get_second_name() = skip_spaces(input);
    }
    while (contact[index].get_second_name().empty());
    do
    {
        std::cout << "Surname: " << std::endl;
        if(!std::getline(std::cin, input))
            exit(1);
        contact[index].get_surname() = skip_spaces(input);
    }
    while (contact[index].get_surname().empty());
    do
    {
        std::cout << "Phone Number: " << std::endl;
        if(!std::getline(std::cin, input))
            exit(1);
        contact[index].get_phone_number() = skip_spaces(input);
    }
    while (contact[index].get_phone_number().empty());
    do
    {
        std::cout << "Darkest Secret: " << std::endl;
        if (!std::getline(std::cin, input))
            exit(1);
        contact[index].get_darkest_secret() = skip_spaces(input);
    }
    while (contact[index].get_darkest_secret().empty());
    index++;
}

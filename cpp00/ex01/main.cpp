#include "PhoneBook.hpp"

int main()
{
    PhoneBook oi;
    std::string input;

    while (1)
    {
        std::cout << "Choose an option: ADD, SEARCH or EXIT. " << std::endl;
        if (!std::getline(std::cin, input))
            break ;
        if (input == "ADD")
        {
            std::cout << "📞 " << "Contact Information:" << std::endl;
            oi.add();
        }
        else if (input == "SEARCH")
        {
            std::cout << "📒 " << "Contacts Table:" << std::endl;
            oi.search();
        }
        else if (input == "EXIT")
        {
            std::cout << "📒 " << "Your list has been deleted!" << std::endl;
            break ;
        }
        else
            std::cout << "invalid option, try: ADD, SEARCH or EXIT!" << std::endl;
    }
}

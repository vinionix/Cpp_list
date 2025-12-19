#include "Harl.hpp"

int main ()
{
	Harl bob;
	std::string input;

	while (1)
	{
		std::cout << "Choose an option:  DEBUG, INFO, WARNING or ERROR. " << std::endl;
        if (!std::getline(std::cin, input))
            break ;
		bob.complain(input);
	}
	
}
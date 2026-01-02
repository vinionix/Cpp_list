# include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon on my 7XL-double-cheese-triple-pickle-ketchup-special burger. I really love it." << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I can't believe adding extra bacon costs more money. You didn't put enough bacon on my burger! If you had, I wouldn't be asking for more!" << std::endl;
}
void	Harl::error( void )
{
	std::cout << "I think I deserve extra bacon for free. I've been coming here for years, while you only started working here last month." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void	Harl::indexError( void )
{
	std::cout << "Invalid option." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	array[4] = {"DEBUG", "INFO", "ERROR", "WARNING"};
	int	i = 0;
	while (i < 4 && array[i] != level)
		i++;
	void	(Harl::*func[5])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::error,
		&Harl::warning,
		&Harl::indexError
	};
	(this->*func[i]) ();
}
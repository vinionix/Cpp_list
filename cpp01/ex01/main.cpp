#include "Zombie.hpp"

int	main()
{
	Zombie* horde = zombieHorde(9, "Bizzarro");

	for (size_t i = 0; i < 9; i++)
		horde[i].announce();
	delete[] horde;
}

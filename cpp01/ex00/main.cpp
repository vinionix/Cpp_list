#include "Zombie.hpp"

int main()
{
    Zombie Roger;
    Zombie *Flavio;

    Roger.randomChump("Roger");
    Flavio = newZombie("Flavio");
    Flavio->announce();
    delete(Flavio);
}

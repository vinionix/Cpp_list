#pragma once
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
		Zombie( void );
        std::string& get_name();
        void randomChump( std::string name );
        void announce( void );
        ~Zombie( void );
};
Zombie* newZombie( std::string name );

#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {

	public:

		Zombie( std::string name = "Casca");
		~Zombie( void );
		void announce( void );

	private:

		std::string	_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif // ZOMBIE_H

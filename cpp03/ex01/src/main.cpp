#include <iostream>
#include "../inc/ScavTrap.hpp"

int main( void )
{
	{
		ScavTrap Ben("Ben");
		Ben.takeDamage(10);
		Ben.attack("John");
		Ben.guardGate();

	}
	{
		ClapTrap Sam("Sam");
		ScavTrap Pete("Pete");

		Sam.attack("Pete");
		Pete.attack("Sam");
		Sam.takeDamage(20);
	}
	{
	//	ScavTrap Bob("Bob");
	//	for (int i = 0; i < 51; ++i)
	//	{
	//		Bob.attack("Jim");
	//	}
	}
	return (0);
}

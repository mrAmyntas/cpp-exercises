#include <iostream>
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main( void )
{
	{
		FragTrap Tim("Tim");
		Tim.takeDamage(10);
		Tim.attack("John");
		Tim.highFivesGuys();
	}
	{
		FragTrap Tim("Tim");
		ClapTrap Sam("Sam");
		ScavTrap Bob("Bob");
		Sam.attack("Bob");
		Bob.takeDamage(0);
		Bob.attack("Bob");
		Bob.takeDamage(20);
		Tim.attack("Bob");
		Bob.takeDamage(30);
	}
	{
		FragTrap Bob("Bob");
		for (int i = 0; i < 101; ++i)
		{
			Bob.attack("Bob");
		}
	}
	return (0);
	
}

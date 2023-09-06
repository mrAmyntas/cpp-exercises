#include <iostream>
#include "../inc/ClapTrap.hpp"

int main( void )
{
	{
		ClapTrap Ben("Ben");

		Ben.attack("Sally");
		Ben.takeDamage(5);
		Ben.beRepaired(2);
		Ben.beRepaired(2);
		Ben.beRepaired(2);
		Ben.beRepaired(2);
		Ben.attack("Sandy");
		Ben.attack("Sarah");
		Ben.attack("Sammy");
		Ben.attack("Sam");
		Ben.attack("Sem");
		Ben.attack("Sebastian");
		Ben.beRepaired(2);
	}
	{ 
		ClapTrap Sally("Sally");

		Sally.takeDamage(224122412);
		Sally.takeDamage(200);
		Sally.attack("Ben");
		Sally.beRepaired(200);
	}
	return 0;
}

#include "../inc/DiamondTrap.hpp"

int main( void )
{
	{
		DiamondTrap Ben("Ben");
		Ben.whoAmI();
		std::cout << Ben.getVal("hp") << std::endl;
		std::cout << Ben.getVal("ep") << std::endl;
		std::cout << Ben.getVal("dmg") << std::endl;
		Ben.attack("Sam");
		Ben.ScavTrap::attack("Sam");
		Ben.FragTrap::attack("Sam");
		Ben.ClapTrap::attack("Sam");

		std::cout << "-----------------------" << std::endl;
		Ben.takeDamage(20);
		DiamondTrap Ben2("Ben2");
		Ben2.takeDamage(10);
		std::cout << Ben2.getVal("hp") << std::endl;
		Ben2 = Ben;
		std::cout << Ben.getVal("hp") << std::endl;
		std::cout << Ben2.getVal("hp") << std::endl;
		Ben2.takeDamage(20);
		std::cout << Ben.getVal("hp") << std::endl;
		std::cout << Ben2.getVal("hp") << std::endl;
		Ben2.guardGate();
		Ben2.highFivesGuys();
	}
	/*{
		std::cout << "-----------------------" << std::endl;
		DiamondTrap Ben("Ben");
		DiamondTrap Ben2(Ben);

		std::cout << Ben2.getVal("hp") << std::endl;
		std::cout << Ben2.getVal("ep") << std::endl;
		std::cout << Ben2.getVal("dmg") << std::endl;
		Ben2.attack("pete");
	}

	{
		DiamondTrap Ben("Ben");
		ClapTrap Clap("Clap");
		ScavTrap Scav("Scav");
		FragTrap Frag("Frag");
		std::cout <<  Clap.getName() << std::endl;
		std::cout <<  Clap.getVal("hp") << std::endl;
		std::cout <<  Clap.getVal("ep") << std::endl;
		std::cout <<  Clap.getVal("dmg") << std::endl;

		Clap = Ben;

		std::cout <<  Clap.getName() << std::endl;
		std::cout <<  Clap.getVal("hp") << std::endl;
		std::cout <<  Clap.getVal("ep") << std::endl;
		std::cout <<  Clap.getVal("dmg") << std::endl;

		Clap = Scav;

		std::cout <<  Clap.getName() << std::endl;
		std::cout <<  Clap.getVal("hp") << std::endl;
		std::cout <<  Clap.getVal("ep") << std::endl;
		std::cout <<  Clap.getVal("dmg") << std::endl;

		Frag = Ben;
		std::cout <<  Frag.getName() << std::endl;
		std::cout <<  Frag.getVal("hp") << std::endl;
		std::cout <<  Frag.getVal("ep") << std::endl;
		std::cout <<  Frag.getVal("dmg") << std::endl;

	}*/
	return 0;

	
}

#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();

	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon("notdrop");
		jim.setWeapon(club);
		jim.setWeapon("notdrop");
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		jim.setWeapon("drop");
		jim.attack();
	}
	return 0;
}

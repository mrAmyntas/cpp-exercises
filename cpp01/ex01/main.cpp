#include "Zombie.hpp"

int	main(void){

	int			num_zombies = 5;
	std::string	zombie_name = "Carl";
	Zombie		*ZombiePtr;

	ZombiePtr = zombieHorde(num_zombies, zombie_name);
	std::cout << "Zombies announcing themselves...\n";

	for (int i = 0; i < num_zombies; i++)
		ZombiePtr[i].announce();

	std::cout << "Deleting the horde...\n";
	delete[] ZombiePtr;

	std::cout << "Press any character to test with 10 zombies and different name...\n";
	getchar();
	ZombiePtr = zombieHorde(10, "NotCarl");
	for (int i = 0; i < 10; i++)
		ZombiePtr[i].announce();
	delete[] ZombiePtr;
	return(0);
}

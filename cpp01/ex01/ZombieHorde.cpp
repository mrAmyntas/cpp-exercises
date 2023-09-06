#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ){

	std::cout << "Allocating for ZombieHorde...\n";
	Zombie *myZombies = new Zombie[N]; //allcation for N zombies

	std::cout << "Naming my Zombies...\n";
	for (int i = 0; i < N; i++)
		myZombies[i].setName(name); //copying the name of namedzombie to my horde of N zombies
	return (myZombies);
}

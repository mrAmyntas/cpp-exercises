#include "Zombie.hpp"

int	main(void){

	//Creating zombie Carl by instantiating an object of class Zombie.
	Zombie Carl("Carl");

	//Can use the announce function to announce Carl.
	Carl.announce();

	//Creating zombie Henry by calling function newZombie which allocates on the heap for a new object of class Zombie
	//and returns a pointer which I can use.
	Zombie *HenryPtr = newZombie("Henry");

	//Can use the announce function to announce Carl. But need to use -> as it is a pointer.
	HenryPtr->announce();

	//To free the heap-memory allocated for Henry we need to call delete, this also calls the destructor.
	delete HenryPtr;

	//Creating zombie Peter with function randomChump which instantiates a new object of class Zombie
	//and it announces itself in its own scope. Peter also gets destroyed when it returns to the main. 
	randomChump("Peter");

	//When main returns Carl gets destroyed.
	return(0);
}
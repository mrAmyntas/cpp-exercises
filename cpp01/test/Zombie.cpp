#include "Zombie.hpp"

//CONSTRUCTOR & DESTRUCTOR
Zombie::Zombie(std::string name) : _name(name) {};
Zombie::~Zombie(void){ std::cout << _name << " was destroyed\n"; };

//ZOMBIE ANNOUNCEMENT
void Zombie::announce( void ){

	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

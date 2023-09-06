#include "Zombie.hpp"

//DEFAULT CONSTRUCTOR
Zombie::Zombie( void ){ std::cout << "Initializing unnamed Zombie\n";}

//CONSTRUCTOR WITH NAME INITIALIZATION
Zombie::Zombie( std::string name ) { std::cout << "Zombie " << name << " initialized\n"; _name = name;}

//DESTRUCTOR				
Zombie::~Zombie(void){ std::cout << _name << " was destroyed\n"; }

//SETTING NAME
void	Zombie::setName(std::string name){ _name = name;}

//ZOMBIE ANNOUNCEMENT
void 	Zombie::announce( void ){ std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";}	

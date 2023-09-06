#include "../inc/HumanB.hpp"

//CONSTRUCTOR
HumanB::HumanB(std::string name){ _name = name;}

//DESTRUCTOR
HumanB::~HumanB(void){ }

//SET WEAPON
void	HumanB::setWeapon(Weapon &weapon){ _Bweapon = &weapon;}
void	HumanB::setWeapon(std::string str)
{
	if (str == "drop")
		_Bweapon = NULL;
}

//ATTACK
void	HumanB::attack(void){

	if (_Bweapon)
		std::cout << _name << " attacks with their " << _Bweapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their fists\n";
}	
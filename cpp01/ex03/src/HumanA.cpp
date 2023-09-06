#include "../inc/HumanA.hpp"

//CONSTRUCTOR
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _Aweapon(weapon) {}

//DESTRUCTOR
HumanA::~HumanA(void){}

//ATTACK
void	HumanA::attack(void){ std::cout << _name << " attacks with their " << _Aweapon.getType() << std::endl;}

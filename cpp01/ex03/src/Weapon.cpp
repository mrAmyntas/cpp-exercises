#include "../inc/Weapon.hpp"

//CONSTRUCTOR
Weapon::Weapon(std::string weapontype){_type = weapontype;}

//DESTRUCTOR
Weapon::~Weapon(void){}

//SET WEAPON TYPE
void	Weapon::setType(std::string new_type){_type = new_type;}

//GET WEAPON TYPE
const std::string&	Weapon::getType(void){ return (_type);}


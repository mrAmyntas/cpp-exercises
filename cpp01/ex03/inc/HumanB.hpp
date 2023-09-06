#pragma once

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {

	public:

		HumanB(std::string name);
		~HumanB();
		
		void	setWeapon(Weapon &weapon);
		void	setWeapon(std::string str);

		void	attack();

	private:

		Weapon		*_Bweapon;
		std::string	_name;
};

#endif // HUMANB_H
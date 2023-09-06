#pragma once

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {

	public:

		HumanA(std::string name, Weapon  &weapon);
		~HumanA();

		void	attack();

	private:

		std::string _name;
		Weapon		&_Aweapon;
		std::string _weapn;
};

#endif // HUMANA_H
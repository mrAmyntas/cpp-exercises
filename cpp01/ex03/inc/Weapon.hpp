#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {

	public:

		Weapon(std::string weapontype);
		~Weapon(void);

		const std::string&	getType(void);
		void				setType(std::string new_type);

	private:
	
		std::string _type;

};

#endif // WEAPON_H
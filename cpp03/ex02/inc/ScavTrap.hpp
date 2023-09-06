#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap(std::string str);
		~ScavTrap( void );
		ScavTrap( ScavTrap const & src );
		ScavTrap &	operator=( ScavTrap const & rhs );

		void attack(const std::string & target);
		void guardGate( void );


};


#endif // SCAVTRAP_HPP
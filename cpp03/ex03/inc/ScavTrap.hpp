#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ClapTrap;

class ScavTrap : virtual public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap(std::string str);
		~ScavTrap( void );
		ScavTrap( ScavTrap const & src );
		ScavTrap &	operator=( ScavTrap const & rhs );

		void attack(const std::string & target);
		void guardGate( void );
		int	 getScavDefault_ep( void ) const;
		
	private:

		const int	_default_ep;

};


#endif // SCAVTRAP_HPP
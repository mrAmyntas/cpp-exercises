#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class ClapTrap;
class ScavTrap;
class FragTrap;

class DiamondTrap : public ScavTrap, public FragTrap {

	public:

		DiamondTrap( void );
		DiamondTrap( std::string str );
		~DiamondTrap( void );
		DiamondTrap( DiamondTrap const & src );
		DiamondTrap &	operator=( DiamondTrap const & rhs );

		using ScavTrap::attack;
		void whoAmI( void );
	
	private:

		std::string _name;
};

#endif // DIAMONDTRAP_HPP
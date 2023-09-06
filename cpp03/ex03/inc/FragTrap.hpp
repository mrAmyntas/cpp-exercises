#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class ClapTrap;

class FragTrap : virtual public ClapTrap {

	public:

		FragTrap( void );
		FragTrap( std::string str );
		~FragTrap( void );
		FragTrap( FragTrap const & src );
		FragTrap &	operator=( FragTrap const & rhs );

		void attack( const std::string& target );
		void highFivesGuys( void );

};


#endif // FRAGTRAP_HPP
#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap;

class ClapTrap {

	public:

		ClapTrap( void );
		ClapTrap( std::string name ); 
		~ClapTrap( void );
		ClapTrap( ClapTrap const & src );
		ClapTrap &	operator=( ClapTrap const & rhs );

		int			getVal( std::string str ) const;
		void		setVal( std::string str, int val );
		std::string	getName( void ) const;
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
	private:

		std::string	_name;
		int			_hp;
		int			_ep;
		int			_dmg;

};

std::ostream & operator<<( std::ostream & o, ClapTrap const & i );

#endif // CLAPTRAP_HPP
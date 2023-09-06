#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {

	public:

		Character( );
		Character( std::string const & name );
		virtual ~Character( );
		Character( Character const & src );
		Character & operator=( Character const & rhs );

		virtual std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
	
		std::string	_name;
		AMateria** 	inv;

};

#endif // CHARACTER_HPP
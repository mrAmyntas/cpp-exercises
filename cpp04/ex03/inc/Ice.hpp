#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {

	private:

		std::string type;

	public:

		Ice( );
		virtual ~Ice( );
		Ice( Ice const & src );
		Ice & operator=( Ice const & rhs );

		std::string const & getType() const;
		Ice* clone() const;
		void use(ICharacter & target);
};


#endif // ANIMAL_HPP
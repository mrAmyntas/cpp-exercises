#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

	private:

		std::string type;

	public:

		Cure( );
		virtual ~Cure( );
		Cure( Cure const & src );
		Cure & operator=( Cure const & rhs );

		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter & target);
};


#endif // CURE_HPP
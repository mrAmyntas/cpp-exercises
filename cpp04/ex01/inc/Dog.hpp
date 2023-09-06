#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		virtual ~Dog( void );
		Dog &	operator=( Dog const & rhs );
		Dog( Dog const & src );

		void 		makeSound( void ) const;
		std::string getType( void ) const;
		void		setType( std::string type);

	private:

		std::string type;
		Brain		*_BrainPTR;

};

#endif // DOG_HPP
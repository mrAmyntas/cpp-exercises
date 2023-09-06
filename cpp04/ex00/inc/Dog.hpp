#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		virtual ~Dog( void );
		Dog( Dog const & src );
		Dog &	operator=( Dog const & rhs );

		void 		makeSound( void ) const;
		std::string getType( void ) const;
		void		setType( std::string type);

	private:

		std::string type;
};

#endif // DOG_HPP
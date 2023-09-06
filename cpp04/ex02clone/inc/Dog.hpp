#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		Dog( std::string str );
		virtual ~Dog( void );
		Dog &	operator=( Dog const & rhs );

		void 		makeSound( void ) const;
		std::string getType( void ) const;
		void		setType( std::string type);
		Animal* 	clone_animal( void );
		Dog* 		clone_dog( void );

	private:

		Dog( Dog const & src );
		std::string _DogType;
		Brain		*_BrainPTR;

};

#endif // DOG_HPP
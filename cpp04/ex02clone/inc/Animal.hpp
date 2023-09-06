#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {

	public:

		Animal( void );
		Animal( std::string str );
		virtual ~Animal();
		Animal & operator=( Animal const & rhs );

		virtual void		makeSound( void ) const = 0;
		virtual void		setType( std::string type);
		virtual std::string getType( void ) const;
		virtual Animal* 	clone_animal( void ) = 0;

	protected:

		Animal( Animal const & src );
		std::string AnimalType;
};

class WrongAnimal {

	public:

		WrongAnimal( void );
		WrongAnimal( std::string str );
		~WrongAnimal( void );
		WrongAnimal & operator=( WrongAnimal const & rhs );

		virtual void		makeSound( void ) const = 0;
		virtual void		setType( std::string type);
		virtual std::string getType( void ) const;
		virtual WrongAnimal* clone_animal( void ) = 0;

	protected:

		WrongAnimal( WrongAnimal const & src );
		std::string AnimalType;
};
#endif // ANIMAL_HPP
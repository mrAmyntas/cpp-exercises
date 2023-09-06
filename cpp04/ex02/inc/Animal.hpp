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
		Animal( Animal const & src );

		virtual void		makeSound( void ) const = 0;
		virtual void		setType( std::string type);
		virtual std::string getType( void ) const;

	protected:

		std::string type;
};

class WrongAnimal {

	public:

		WrongAnimal( void );
		WrongAnimal( std::string str );
		virtual ~WrongAnimal( void );
		WrongAnimal & operator=( WrongAnimal const & rhs );
		WrongAnimal( WrongAnimal const & src );

		virtual void			makeSound( void ) const = 0;
		virtual void			setType( std::string type);
		virtual std::string 	getType( void ) const;

	protected:

		std::string type;
};
#endif // ANIMAL_HPP
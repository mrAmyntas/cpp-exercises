#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

	public:

		Animal( );
		Animal( std::string str );
		virtual ~Animal();
		Animal & operator=( Animal const & rhs );
		Animal( Animal const & src );

		virtual void		makeSound( void ) const;
		virtual void		setType( std::string type);
		virtual std::string getType( void ) const;

	protected:

		std::string type;
};

class WrongAnimal {

	public:

		WrongAnimal( void );
		WrongAnimal( std::string str );
		~WrongAnimal( void );
		WrongAnimal( WrongAnimal const & src );
		WrongAnimal & operator=( WrongAnimal const & rhs );

		void	makeSound( void ) const;
		void	setType( std::string type);
		std::string getType( void ) const;
		
	protected:

		std::string type;
};
#endif // ANIMAL_HPP
#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat( );
		virtual ~Cat( );
		Cat( Cat const & src );
		Cat & operator=( Cat const & rhs );

		void		setType( std::string type);
		std::string	getType( void ) const;
		void		makeSound( void ) const;

	private:

		std::string type;
};


class WrongCat : public WrongAnimal {

	public:

		WrongCat( void );
		~WrongCat( void );
		WrongCat( WrongCat const & src );
		WrongCat & operator=( WrongCat const & rhs );

 		void		setType( std::string type);
		std::string getType( void ) const;
		void 		makeSound( void ) const;

	private:

		std::string type;
};

#endif // CAT_HPP
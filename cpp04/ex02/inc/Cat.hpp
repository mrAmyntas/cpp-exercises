#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat( void );
		virtual ~Cat( void );
		Cat & operator=( Cat const & rhs );
		Cat( Cat const & src );

		void		setType( std::string type);
		std::string	getType( void ) const;
		void		makeSound( void ) const;

	private:

		std::string type;
		Brain		*_BrainPTR;

};


class WrongCat : public WrongAnimal {

	public:

		WrongCat( void );
		virtual ~WrongCat( void );
		WrongCat & operator=( WrongCat const & rhs );
		WrongCat( WrongCat const & src );

 		void			setType( std::string type);
		std::string	 	getType( void ) const;
		void 			makeSound( void ) const;

	private:

		std::string type;
		Brain		*_BrainPTR;

};

#endif // CAT_HPP
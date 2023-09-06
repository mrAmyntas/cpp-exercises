#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat( void );
		Cat( std::string str );
		virtual ~Cat( void );
		Cat & operator=( Cat const & rhs );

		void		setType( std::string type);
		std::string	getType( void ) const;
		void		makeSound( void ) const;
		Animal* 	clone_animal( void );
		Cat* 		clone_cat( void );

	private:

		Cat( Cat const & src );
		std::string _CatType;
		Brain		*_BrainPTR;

};


class WrongCat : public WrongAnimal {

	public:

		WrongCat( void );
		WrongCat( std::string str );
		~WrongCat( void );
		WrongCat & operator=( WrongCat const & rhs );

 		void			setType( std::string type);
		std::string 	getType( void ) const;
		void 			makeSound( void ) const;
		WrongAnimal*	clone_animal( void );
		WrongCat* 		clone_cat( void );

	private:

		WrongCat( WrongCat const & src );

		std::string _CatType;
		Brain		*_BrainPTR;

};

#endif // CAT_HPP
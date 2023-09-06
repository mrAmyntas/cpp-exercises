#include "../inc/Cat.hpp"

//CONSTRUCTORS
//DEFAULT
Cat::Cat( void ) : Animal("Cat"), type("Cat")
{ 
	std::cout << "Default Cat constructor called" << std::endl;
	this->_BrainPTR = new Brain();
};
//COPY
Cat::Cat( Cat const & src ) : Animal(src)
{ 
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_BrainPTR = new Brain();
	*this = src;
}
//ASSIGNMENT =
Cat & Cat::operator=( Cat const & src ) 
{
	std::cout << "Cat Assignment operator called" << std::endl; 
	this->type = src.type;
	this->Animal::setType(src.type);
	for (int i = 0; i < 100; i++)
		this->_BrainPTR->ideas[i] = src._BrainPTR->ideas[i];
	return (*this);
}
//DESTRUCTOR
Cat::~Cat( void )
{ 
	std::cout << "Cat Destructor called" << std::endl; 
	delete this->_BrainPTR;
}
//MAKE SOUND
void		Cat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}
//GET ANIMAL TYPE
std::string Cat::getType( void ) const { return (this->type); }
void		Cat::setType( std::string type) { this->type = type; }


//----------------------------------------------
//		WRONG	CAT
//
//----------------------------------------------

//CONSTRUCTORS
//DEFAULT
WrongCat::WrongCat( void ) : WrongAnimal("WrongCat"), type("WrongCat"){ std::cout << "Default WrongCat constructor called" << std::endl; };
//COPY
WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal(src)
{ 
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->_BrainPTR = new Brain();
	*this = src;
}
//ASSIGNMENT =
WrongCat & WrongCat::operator=( WrongCat const & src ) 
{
	std::cout << "WrongCat Assignment operator called" << std::endl; 
	this->type = src.type;
	this->type = src.type;
	for (int i = 0; i < 100; i++)
		this->_BrainPTR->ideas[i] = src._BrainPTR->ideas[i];
	return (*this);
}
//DESTRUCTOR
WrongCat::~WrongCat( void )
{ 
	std::cout << "WrongCat Destructor called" << std::endl;
	delete this->_BrainPTR;
}
//MAKE SOUND
void		WrongCat::makeSound( void ) const
{
	std::cout << "Wrong Meow" << std::endl;
}
//GET ANIMAL TYPE
std::string WrongCat::getType( void ) const { return (type); }
void		WrongCat::setType( std::string type) { this->type = type; }

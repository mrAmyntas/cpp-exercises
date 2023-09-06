#include "../inc/Dog.hpp"

//CONSTRUCTORS
//DEFAULT
Dog::Dog( void ) : Animal("Dog"), type("Dog") { std::cout << "Default Dog constructor called" << std::endl; };
//COPY
Dog::Dog( Dog const & src ) : Animal(src)
{ 
	std::cout << "Dog Copy constructor called" << std::endl; 
	*this = src;
}
//ASSIGNMENT =
Dog & Dog::operator=( Dog const & src ) 
{
	std::cout << "Dog Assignment operator called" << std::endl; 
	this->Animal::setType(src.type);
	this->type = src.type;
	return (*this);
}
//DESTRUCTOR
Dog::~Dog( void ){ std::cout << "Dog Destructor called" << std::endl; }
//MAKE SOUND
void		Dog::makeSound( void ) const
{
	std::cout << "Woof" << std::endl;
}
//GET SET ANIMAL TYPE
std::string Dog::getType( void ) const { return (type); }
void		Dog::setType( std::string ntype) { this->type = ntype; }

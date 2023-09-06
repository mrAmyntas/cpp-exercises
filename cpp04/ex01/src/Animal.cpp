#include "../inc/Animal.hpp"

//CONSTRUCTORS
//DEFAULT
Animal::Animal( void ) { std::cout << "Default Animal constructor called" << std::endl; };
//WITH STRING
Animal::Animal( std::string type ) : type(type)
{ 
	std::cout << "String Animal Constructor called" << std::endl; 
}
//COPY
Animal::Animal( Animal const & src )
{ 
	std::cout << "Animal Copy constructor called" << std::endl; 
	*this = src;
}

//ASSIGNMENT =
Animal & Animal::operator=( Animal const & src ) 
{
	std::cout << "Animal Assignment operator called" << std::endl; 
	this->type = src.type;
	return (*this);
}
//DESTRUCTOR
Animal::~Animal( void ){ std::cout << "Animal Destructor called" << std::endl; }
//GET / SET TYPE
void		Animal::setType( std::string type ) { this->type = type; }
std::string Animal::getType( void ) const { return (type); }

//MAKE SOUND
void		Animal::makeSound( void ) const
{
	if (!this->getType().empty())
		std::cout 	<< "The " << this->getType() << " makes " << this->getType() << " noises!"  << std::endl;
	else
		std::cout 	<< "Unknown animal makes unknown animal noises!" << std::endl;
}

//----------------------------------------------
//		WRONG	ANIMAL
//
//----------------------------------------------

//CONSTRUCTORS
//DEFAULT
WrongAnimal::WrongAnimal( void ) { std::cout << "Default WrongAnimal constructor called" << std::endl; };
//WITH STRING
WrongAnimal::WrongAnimal( std::string type ) : type(type)
{ 
	std::cout << "String WrongAnimal Constructor called" << std::endl; 
}
//COPY
WrongAnimal::WrongAnimal( WrongAnimal const & src )
{ 
	std::cout << "WrongAnimal Copy constructor called" << std::endl; 
	*this = src;
}
//ASSIGNMENT =
WrongAnimal & WrongAnimal::operator=( WrongAnimal const & src ) 
{
	std::cout << "WrongAnimal Assignment operator called" << std::endl; 
	this->type 	= src.type;
	return (*this);
}
//DESTRUCTOR
WrongAnimal::~WrongAnimal( void ){ std::cout << "WrongAnimal Destructor called" << std::endl; }
//GET / SET TYPE
void		WrongAnimal::setType( std::string type ) { this->type = type; }
std::string WrongAnimal::getType( void ) const { return (type); }
//MAKE SOUND
void		WrongAnimal::makeSound( void ) const
{
	if (!this->getType().empty())
		std::cout 	<< "The " << this->getType() << " makes " << this->getType() << " noises!"  << std::endl;
	else
		std::cout 	<< "Unknown WrongAnimal makes unknown WrongAnimal noises!" << std::endl;
}

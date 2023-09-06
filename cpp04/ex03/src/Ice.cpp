#include "../inc/Ice.hpp"

//CONSTRUCTORS
//DEFAULT
Ice::Ice( void ) : AMateria("ice"), type("ice") { std::cout << "Default Ice constructor called" << std::endl; };
//COPY
Ice::Ice( Ice const & src )
{ 
	std::cout << "Ice Copy constructor called" << std::endl; 
	*this = src;
}
//ASSIGNMENT =
Ice & Ice::operator=( Ice const & src ) 
{
	std::cout << "Ice Assignment operator called" << std::endl;
	this->type = src.getType();
	return (*this);
}
//DESTRUCTOR
Ice::~Ice( void ){ std::cout << "Ice Destructor called" << std::endl; }

//GET TYPE
std::string const & Ice::getType( void ) const { return this->type; }

//CLONE
Ice* Ice::clone( ) const
{
	Ice *new_ice = new Ice;
	return (new_ice);
}
//USE
void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


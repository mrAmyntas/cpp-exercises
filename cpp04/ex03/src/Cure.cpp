#include "../inc/Cure.hpp"

//CONSTRUCTORS
//DEFAULT
Cure::Cure( void ) : AMateria("cure"), type("cure") { std::cout << "Default Cure constructor called" << std::endl; };
//COPY
Cure::Cure( Cure const & src )
{ 
	std::cout << "Cure Copy constructor called" << std::endl; 
	*this = src;
}
//ASSIGNMENT =
Cure & Cure::operator=( Cure const & src ) 
{
	std::cout << "Cure Assignment operator called" << std::endl;
	this->type = src.getType();
	return (*this);
}
//DESTRUCTOR
Cure::~Cure( void ){ std::cout << "Cure Destructor called" << std::endl; }

//GET TYPE
std::string const & Cure::getType( void ) const { return this->type; }

//CLONE
Cure* Cure::clone( ) const
{
	Cure *new_Cure = new Cure;
	return (new_Cure);
}
//USE
void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

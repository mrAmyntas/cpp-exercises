#include "../inc/AMateria.hpp"
#include "../inc/Character.hpp"
//CONSTRUCTORS
//DEFAULT
AMateria::AMateria( void ) : type("empty")
{
	std::cout << "Default AMateria constructor called" << std::endl;
};
AMateria::AMateria( std::string const & type ) : type(type)
{
	std::cout << "String AMateria constructor called" << std::endl;
};
//ASSIGNMENT =
AMateria & AMateria::operator=( AMateria const & src ) 
{
	std::cout << "AMateria Assignment operator called" << std::endl; 
	this->type = src.type;
	return (*this);
}
//DESTRUCTOR
AMateria::~AMateria( void )
{ 
	std::cout << "AMateria Destructor called" << std::endl;
	//system("leaks Zoo");
}

//GET
std::string const & AMateria::getType() const
{
	return(type);
}
//USE
void AMateria::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

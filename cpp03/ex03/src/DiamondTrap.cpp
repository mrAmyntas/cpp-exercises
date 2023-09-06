#include "../inc/DiamondTrap.hpp"

//CONSTRUCTORS
//DEFAULT
DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() { std::cout << "DiamondTrap default constructor called" << std::endl; }
//STRING
DiamondTrap::DiamondTrap( std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{ 
	std::cout << "DiamondTrap String constructor called" << std::endl;
	this->setVal("ep", getScavDefault_ep());
}
//DESTRUCTOR
DiamondTrap::~DiamondTrap( void )
{ 
	std::cout << "DiamondTrap destructor called" << std::endl;
}
//COPY
DiamondTrap::DiamondTrap( DiamondTrap const & rhs ) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = rhs;
}
//ASSIGNMENT
DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs ) 
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}
//WHO AM I
void DiamondTrap::whoAmI( void )
{
	std::cout 	<< "my name is " << _name << std::endl
				<<  "my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
#include "../inc/ScavTrap.hpp"

//CONSTRUCTOR
//DEFAULT
ScavTrap::ScavTrap( void ) : ClapTrap(), _default_ep(50) { std::cout << "ScavTrap default constructor called" << std::endl; }
//STRING
ScavTrap::ScavTrap( std::string name) : ClapTrap(name), _default_ep(50)
{ 
	std::cout << "ScavTrap String constructor called" << std::endl;
	setVal("hp", 100);
	setVal("ep", 50);
	setVal("dmg", 20);
}
//DESTRUCTOR
ScavTrap::~ScavTrap( void )
{ 
	std::cout << "ScavTrap destructor called" << std::endl;
}
//COPY
ScavTrap::ScavTrap( ScavTrap const & rhs ) : ClapTrap(rhs), _default_ep(50)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = rhs;
}
//ASSIGNMENT
ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) 
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

//GATE KEEPER MODE
void ScavTrap::guardGate( void )
{
	std::cout << this->getName() << " is now in Gate keeper mode." << std::endl;
}

//ATTACK
void ScavTrap::attack(const std::string & target)
{ 
	if (this->getVal("hp") <= 0)
	{
		std::cout	<< this->getName() << " can't slap " << target 
					<< " because " << this->getName() << " is dead." << std::endl;
	}
	else if (this->getVal("ep") == 0)
	{
		std::cout	<< this->getName() << " can't slap " << target 
					<< " because " << this->getName() << " is out of energy." << std::endl;
	}
	else
	{
		std::cout	<< this->getName() << " slaps " << target << ", causing "
					<< this->getVal("dmg") << " points of damage!" << std::endl;
	}
	if (this->getVal("ep") != 0)
		this->setVal("ep", this->getVal("ep") - 1);
}

//GET EP
int	 ScavTrap::getScavDefault_ep( void ) const { return (_default_ep); }


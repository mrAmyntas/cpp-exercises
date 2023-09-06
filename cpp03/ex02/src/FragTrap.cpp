#include "../inc/FragTrap.hpp"

//CONSTRUCTOR
//DEFAULT
FragTrap::FragTrap( void ) : ClapTrap() { std::cout << "FragTrap constructor called" << std::endl; }
//STRING
FragTrap::FragTrap( std::string name) : ClapTrap(name)
{ 
	std::cout << "FragTrap string constructor called" << std::endl;
	setVal("hp", 100);
	setVal("ep", 100);
	setVal("dmg", 30);
}
//DESTRUCTOR
FragTrap::~FragTrap( void )
{ 
	std::cout << "FragTrap destructor called" << std::endl;
}
//COPY
FragTrap::FragTrap( FragTrap const & rhs ) : ClapTrap(rhs)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = rhs;
}
//ASSIGNMENT
FragTrap & FragTrap::operator=( FragTrap const & rhs ) 
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

//HIGH FIVES
void FragTrap::highFivesGuys( void )
{
	std::cout << this->getName() << ": HIGH FIVE GUYS!!" << std::endl;
}

//ATTACK
void FragTrap::attack(const std::string & target)
{ 
	if (this->getVal("hp") <= 0)
	{
		std::cout	<< this->getName() << " can't kick " << target 
					<< " because " << this->getName() << " is dead." << std::endl;
	}
	else if (this->getVal("ep") == 0)
	{
		std::cout	<< this->getName() << " can't kick " << target 
					<< " because " << this->getName() << " is out of energy." << std::endl;
	}
	else
	{
		std::cout	<< this->getName() << " kicks " << target << ", causing "
					<< this->getVal("dmg") << " points of damage!" << std::endl;
	}
	if (this->getVal("ep") != 0)
		this->setVal("ep", this->getVal("ep") - 1);
}
#include "../inc/ClapTrap.hpp"

//CONSTRUCTORS
//DEFAULT
ClapTrap::ClapTrap( void ) : _hp(10), _ep(10), _dmg(0) { std::cout << "Default ClapTrap constructor called" << std::endl; };
//WITH STRING
ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _dmg(0) 
{ 
	std::cout << "ClapTrap String  Constructor called" << std::endl; 
}
//COPY
ClapTrap::ClapTrap( ClapTrap const & src )
{ 
	std::cout << "ClapTrap Copy constructor called" << std::endl; 
	*this = src;
}
//ASSIGNMENT =
ClapTrap & ClapTrap::operator=( ClapTrap const & src ) 
{
	std::cout << "ClapTrap Assignment operator called" << std::endl; 
	this->_name = src._name;
	this->_hp	= src._hp;
	this->_ep	= src._ep;
	this->_dmg 	= src._dmg;
	return (*this);
}
//DESTRUCTOR
ClapTrap::~ClapTrap( void ){ std::cout << "ClapTrap Destructor called" << std::endl; }

//SET VAL - GET VAL
int ClapTrap::getVal( std::string str ) const {
	
	if (str.compare("hp") == 0)
		return (this->_hp);
	if (str.compare("ep") == 0)
		return (this->_ep);
	if (str.compare("dmg") == 0)
		return (this->_dmg);
	return (-1);
};

void ClapTrap::setVal(std::string str, int val){
	
	if (str.compare("hp") == 0)
		this->_hp = val;
	if (str.compare("ep") == 0)
		this->_ep = val;
	if (str.compare("dmg") == 0)
		this->_dmg = val;
}

std::string	ClapTrap::getName( void ) const { return (_name); }

//ATTACK / TAKE DAMAGE / BE REPAIRED
void ClapTrap::attack(const std::string& target)
{ 
	if (_hp <= 0)
	{
		std::cout	<< this->_name << " can't hit " << target 
					<< " because " << this->_name << " is dead." << std::endl;
	}
	else if (_ep == 0)
	{
		std::cout	<< this->_name << " can't hit " << target 
					<< " because " << this->_name << " is out of energy." << std::endl;
	}
	else
	{
		std::cout	<< this->_name << " hits " << target << ", causing "
					<< this->_dmg << " points of damage!" << std::endl;
	}
	if (_ep != 0)
		this->_ep--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout	<< this->_name << " is already dead why are you doing this :(" << std::endl;
		return ;
	}
	this->_hp = _hp - amount;
	if (_hp <= 0)
	{
		std::cout	<< this->_name << " takes " << amount << " points of damage. "
					<< this->_name << " died :(" << std::endl;
	}
	else
	{
		std::cout	<< this->_name << " takes " << amount << " points of damage. "
					<< this->_name << "'s current health is now: "
					<< this->_hp << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	
	if (_hp <= 0)
	{
		std::cout	<< this->_name << " can't repair because " << this->_name << " is dead." << std::endl;
		return ;
	}
	else if (_ep == 0)
		std::cout	<< this->_name << " can't repair because " << this->_name << " is out of energy." << std::endl;
	else if (_hp == 10)
		std::cout	<< this->_name << " wastes energy repairing non-existent damage." << std::endl;
	else
	{
		std::cout	<< this->_name << " repairs " << amount << " points of damage. "
					<< this->_name << "'s current health is now: ";
		this->_hp = this->_hp + amount;
		if (this->_hp > 10)
			this->_hp = 10;
		std::cout	<< this->_hp << std::endl;
	}
	if (_ep != 0)
		this->_ep--;
}

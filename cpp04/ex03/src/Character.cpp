#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

//CONSTRUCTORS
//DEFAULT
Character::Character( void ) : _name("unnamed") 
{ 
	std::cout << "Default Character constructor called" << std::endl;
	this->inv = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inv[i] = 0;
}
//STRING
Character::Character( std::string const & name ) : _name(name)
{ 
	std::cout << "String Character constructor called" << std::endl;
	this->inv = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inv[i] = 0;
}
//COPY
Character::Character( Character const & src )
{ 
	std::cout << "Character Copy constructor called" << std::endl;
	this->inv = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inv[i] = 0;
	*this = src;
}
//ASSIGNMENT =
Character & Character::operator=( Character const & src ) 
{
	std::cout << "Character Assignment operator called" << std::endl;
	this->_name = src.getName();
	for (int i = 0; i < 4; ++i)
	{
		if (src.inv[i] != 0)
		{
			if (src.inv[i]->getType().compare("ice") == 0)
			{
				AMateria *newMateria = new Ice();
				if (this->inv[i] != 0)
					delete this->inv[i];
				this->inv[i] = newMateria;
			}
			else if (this->inv[i]->getType().compare("cure") == 0)
			{
				AMateria *newMateria = new Cure();
				if (this->inv[i] != 0)
					delete this->inv[i];
				this->inv[i] = newMateria;
			}
			else
				this->inv[i] = 0;
		}
	}
	return (*this);
}
//DESTRUCTOR
Character::~Character( void )
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inv[i] != 0)
		{
			delete this->inv[i];
			this->inv[i] = 0;
		}
	}
	delete [] this->inv;
	//system("leaks Zoo");
}
//GET NAME
std::string const & Character::getName( void ) const { return _name; }
//EQUIP
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->inv[i] != 0)
		{
			if (m == this->inv[i])
				return ;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (this->inv[i] == 0)
		{
			this->inv[i] = m;
			return ;
		}
	}
}
//UNEQUIP
void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 4)
		this->inv[idx] = 0;
}
//USE
void Character::use(int idx, ICharacter& target)
{
	if (this->inv[idx] != 0)
		this->inv[idx]->use(target);
	else
		std::cout << "* has nothing equipped in this slot and looks like a fool *" << std::endl;
}

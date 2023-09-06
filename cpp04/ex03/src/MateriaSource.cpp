#include "../inc/MateriaSource.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

//CONSTRUCTORS
//DEFAULT
MateriaSource::MateriaSource( void )
{ 
	std::cout << "Default MateriaSource constructor called" << std::endl;
	this->inv = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inv[i] = 0;
}
//COPY
MateriaSource::MateriaSource( MateriaSource const & src )
{ 
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	this->inv = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inv[i] = 0;
	*this = src;
}
//ASSIGNMENT =
MateriaSource & MateriaSource::operator=( MateriaSource const & src ) 
{
	std::cout << "MateriaSource Assignment operator called" << std::endl;
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
MateriaSource::~MateriaSource( void )
{
	std::cout << "MateriaSource Destructor called" << std::endl;
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
//LEARN MATERIA
void MateriaSource::learnMateria( AMateria * m )
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->inv[i] == 0)
		{
			this->inv[i] = m;
			return ;
		}
	}
	delete m;

}
//CREATE MATERIA
AMateria* MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->inv[i] != 0)
		{
			if (this->inv[i]->getType().compare(type) == 0 && type.compare("ice") == 0)
			{
				AMateria *new_materia = new Ice();
				return (new_materia);
			}
			if (this->inv[i]->getType().compare(type) == 0 && type.compare("cure") == 0)
			{
				AMateria *new_materia = new Cure();
				return (new_materia);
			}
		}
	}
	return 0;
}

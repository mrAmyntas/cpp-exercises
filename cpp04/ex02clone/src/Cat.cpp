#include "../inc/Cat.hpp"

//CONSTRUCTORS
//DEFAULT
Cat::Cat( void ) : Animal("Cat")
{ 
	std::cout << "Default Cat constructor called" << std::endl;
	this->_BrainPTR = new Brain();
};
//WITH STRING
Cat::Cat( std::string type ) : Animal("Cat"), _CatType(type)
{ 
	std::cout << "String Cat Constructor called" << std::endl;
	this->_BrainPTR = new Brain();
}
//COPY
Cat::Cat( Cat const & src ) : Animal(src)
{ 
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_BrainPTR = new Brain();
	*this = src;
}
//CLONE
Animal* Cat::clone_animal( void )
{
	std::cout << "Cloning Cat object\n";
	return (new Cat(*this));
}
Cat* Cat::clone_cat( void )
{
	std::cout << "Cloning Cat object\n";
	return (new Cat(*this));
}
//ASSIGNMENT =
Cat & Cat::operator=( Cat const & src ) 
{
	std::cout << "Cat Assignment operator called" << std::endl; 
	this->_CatType = src._CatType;
	this->Animal::setType(src.AnimalType);
	for (int i = 0; i < 100; i++)
		this->_BrainPTR->ideas[i] = src._BrainPTR->ideas[i];
	return (*this);
}
//DESTRUCTOR
Cat::~Cat( void )
{ 
	std::cout << "Cat Destructor called" << std::endl; 
	delete this->_BrainPTR;
}
//MAKE SOUND
void		Cat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}
//GET ANIMAL TYPE
std::string Cat::getType( void ) const { return (this->_CatType); }
void		Cat::setType( std::string type) { _CatType = type; }


//----------------------------------------------
//		WRONG	CAT
//
//----------------------------------------------

//CONSTRUCTORS
//DEFAULT
WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") { std::cout << "Default WrongCat constructor called" << std::endl; };
//WITH STRING
WrongCat::WrongCat( std::string type ) : WrongAnimal("WrongCat"), _CatType(type)
{ 
	std::cout << "String WrongCat Constructor called" << std::endl; 
}
//COPY
WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal(src)
{ 
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = src;
}
//CLONE
WrongAnimal* WrongCat::clone_animal( void )
{
	std::cout << "Cloning Cat object\n";
	this->_BrainPTR = new Brain();
	return (new WrongCat(*this));
}
WrongCat* WrongCat::clone_cat( void )
{
	std::cout << "Cloning WrongCat object\n";
	return (new WrongCat(*this));
}
//ASSIGNMENT =
WrongCat & WrongCat::operator=( WrongCat const & src ) 
{
	std::cout << "WrongCat Assignment operator called" << std::endl; 
	this->AnimalType = src.AnimalType;
	this->_CatType = src._CatType;
	for (int i = 0; i < 100; i++)
		this->_BrainPTR->ideas[i] = src._BrainPTR->ideas[i];
	return (*this);
}
//DESTRUCTOR
WrongCat::~WrongCat( void )
{ 
	std::cout << "WrongCat Destructor called" << std::endl;
	delete this->_BrainPTR;
}
//MAKE SOUND
void		WrongCat::makeSound( void ) const
{
	std::cout << "Wrong Meow" << std::endl;
}
//GET ANIMAL TYPE
std::string WrongCat::getType( void ) const { return (_CatType); }
void		WrongCat::setType( std::string type) { _CatType = type; }

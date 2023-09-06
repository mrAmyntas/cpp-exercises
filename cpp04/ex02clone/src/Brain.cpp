#include "../inc/Brain.hpp"

//CONSTRUCTORS
//DEFAULT
Brain::Brain( void )
{
	std::cout << "Default Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "empty";
};
//WITH STRING
Brain::Brain( std::string new_ideas[100] )
{
	std::cout << "String Brain Constructor called" << std::endl;  
	for (int i = 0; i < 100; i++)
		this->ideas[i] = new_ideas[i];
}
//COPY
Brain::Brain( Brain const & src )
{ 
	std::cout << "Brain Copy constructor called" << std::endl; 
	*this = src;
}
//ASSIGNMENT =
Brain & Brain::operator=( Brain const & src ) 
{
	std::cout << "Brain Assignment operator called" << std::endl; 
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return (*this);
}
//DESTRUCTOR
Brain::~Brain( void ){ std::cout << "Brain Destructor called" << std::endl; }

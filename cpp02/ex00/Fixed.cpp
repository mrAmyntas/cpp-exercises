#include "Fixed.hpp"

//CONSTRUCTOR
Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called\n";
}

//COPY
Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called\n";
	*this = src;
	//this->_value = rhs.getRawBits();
}

//ASSIGNMENT 
Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called\n";
	this->_value = rhs.getRawBits();
	return (*this);
}

//DESTRUCTOR
Fixed::~Fixed( void )
{
	std::cout << "Destructor called\n";
}

//<<
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.getRawBits();
	return o;
}


//GET - SET
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
}

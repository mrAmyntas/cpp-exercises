#include "Fixed.hpp"

//CONSTRUCTORS
//DEFAULT
Fixed::Fixed( void ) : _value(0) { std::cout << "Default constructor called\n"; }
//INT
Fixed::Fixed( const int i ) { this->_value = (i << _bits); std::cout << "Int constructor called\n"; }
//FLOAT
Fixed::Fixed( const float p ){ this->_value = roundf(p * (1 << _bits)); std::cout << "Float constructor called\n"; }
//COPY
Fixed::Fixed( Fixed const & src ){ this->_value = src.getRawBits(); std::cout << "Copy constructor called\n"; }
//ASSIGNMENT =
Fixed & Fixed::operator=( Fixed const & rhs )
{
	this->_value = rhs.getRawBits();
	std::cout << "Copy assignment operator called\n";
	return (*this);
}
//DESTRUCTOR
Fixed::~Fixed( void ){ std::cout << "Destructor called\n"; }

//<<
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

//GET - SET
int		Fixed::getRawBits( void ) const { return (this->_value); }
void	Fixed::setRawBits( int const raw ) { this->_value = raw; }

//toFloat - toInt
float	Fixed::toFloat( void ) const
{
	return ((float)this->_value / (float)(1 << _bits));
}

int		Fixed::toInt( void ) const
{
	return (this->_value / (1 << _bits));
}

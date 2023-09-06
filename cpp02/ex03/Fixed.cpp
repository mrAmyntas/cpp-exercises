#include "Fixed.hpp"

//CONSTRUCTORS
//DEFAULT
Fixed::Fixed( void ) : _value(0) {}
//INT
Fixed::Fixed( const int i ) { this->_value = (i << _bits); }
//FLOAT
Fixed::Fixed( const float f ){ this->_value = roundf(f * (1 << _bits)); }
//COPY
Fixed::Fixed( Fixed const & src ){ *this = src; }
//ASSIGNMENT =
Fixed & Fixed::operator=( Fixed const & rhs )
{
	this->_value = rhs.getRawBits();
	return (*this);
}
//DESTRUCTOR
Fixed::~Fixed( void ){ }

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

//Comparisan operators
bool Fixed::operator>( Fixed const & rhs )
{
	if (this->_value > rhs._value)
		return (true);
	return (false);
}
bool Fixed::operator<( Fixed const & rhs )
{
	if (this->_value < rhs._value)
		return (true);
	return (false);
}
bool Fixed::operator>=( Fixed const & rhs )
{
	if (this->_value >= rhs._value)
		return (true);
	return (false);
}
bool Fixed::operator<=( Fixed const & rhs )
{
	if (this->_value <= rhs._value)
		return (true);
	return (false);
}
bool Fixed::operator==( Fixed const & rhs )
{
	if (this->_value == rhs._value)
		return (true);
	return (false);
}
bool Fixed::operator!=( Fixed const & rhs )
{
	if (this->_value != rhs._value)
		return (true);
	return (false);
}

//arithmetic operators
Fixed Fixed::operator+( Fixed const & rhs )
{
	Fixed tmp(*this);
	tmp._value = this->_value + rhs._value;
	return (tmp);
}
Fixed Fixed::operator-( Fixed const & rhs )
{
	Fixed tmp(*this);
	tmp._value = this->_value - rhs._value;
	return (tmp);
}
Fixed Fixed::operator*( Fixed const & rhs )
{
	Fixed tmp(*this);
	tmp._value = this->_value * rhs._value / (1 << _bits);
	return (tmp);
}
Fixed Fixed::operator/( Fixed const & rhs )
{
	Fixed tmp(*this);
	if (rhs._value != 0)
		tmp._value = (this->_value * (1 << _bits)) / rhs._value;
	return (tmp);
}

//incr/decre operators
Fixed Fixed::operator++( int n )
{
	Fixed tmp(*this);

	if (n == 0)
		operator++();
	for (int i = 0; i < n; i++)
		operator++();
	return (tmp);
}
Fixed Fixed::operator++( void )
{
	this->_value = this->_value + 1;
	return (*this);
}
Fixed Fixed::operator--( int n )
{
	Fixed tmp(*this);

	if (n == 0)
		operator--();
	for (int i = 0; i < n; i++)
		operator--();
	return (tmp);
}
Fixed Fixed::operator--( void )
{
	this->_value = this->_value - 1;
	return (*this);
}

// MIN - MAX
const Fixed & Fixed::min( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs._value > rhs._value)
	{
		const Fixed & tmp(rhs);
		return (tmp);
	}
	const Fixed & tmp(lhs);
	return (tmp);
}
Fixed & Fixed::min( Fixed & lhs, Fixed & rhs )
{
	if (lhs._value > rhs._value)
	{
		Fixed & tmp(rhs);
		return (tmp);
	}
	Fixed & tmp(lhs);
	return (tmp);
}
const Fixed & Fixed::max( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs._value < rhs._value)
	{
		const Fixed & tmp(rhs);
		return (tmp);
	}
	const Fixed & tmp(lhs);
	return (tmp);
}
Fixed & Fixed::max( Fixed & lhs, Fixed & rhs )
{
	if (lhs._value < rhs._value)
	{
		Fixed & tmp(rhs);
		return (tmp);
	}
	Fixed & tmp(lhs);
	return (tmp);
}

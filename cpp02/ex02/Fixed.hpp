#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed;

class Fixed {

	public:

		Fixed( void );
		Fixed( const int i ); 
		Fixed( const float p ); 
		~Fixed( void );
		Fixed( Fixed const & src );
		Fixed &	operator=( Fixed const & rhs );

		bool	operator>( Fixed const & rhs );
		bool	operator<( Fixed const & rhs );
		bool	operator>=( Fixed const & rhs );
		bool	operator<=( Fixed const & rhs );
		bool	operator==( Fixed const & rhs );
		bool	operator!=( Fixed const & rhs );

		Fixed	operator+( Fixed const & rhs );
		Fixed	operator-( Fixed const & rhs );
		Fixed	operator*( Fixed const & rhs );
		Fixed	operator/( Fixed const & rhs );

		Fixed	operator++( void );
		Fixed	operator++( int n );
		Fixed	operator--( void );
		Fixed	operator--( int n );

		static const	Fixed	&	min( Fixed const & lhs, Fixed const & rhs );
		static			Fixed	&	min( Fixed & lhs, Fixed & rhs );
		static const 	Fixed	&	max( Fixed const & lhs, Fixed const & rhs );
		static 			Fixed	&	max( Fixed & lhs, Fixed & rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:

		int 				_value;
		static const int 	_bits = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif // FIXED_HPP
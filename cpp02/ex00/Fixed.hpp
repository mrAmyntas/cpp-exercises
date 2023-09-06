#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed;

class Fixed {

	public:

		Fixed( void ); 
		~Fixed( void );
		Fixed( Fixed const & src );
		Fixed & operator=( Fixed const & rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		int 				_value;
		static const int 	_bits = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
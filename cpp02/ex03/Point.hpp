#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

	public:

		Point( void );
		Point( const float f1, const float f2 ); 
		~Point( void );
		Point( Point const & src );
		Point &	operator=( Point const & rhs );
		Fixed	get_x( void ) const ;
		Fixed	get_y( void ) const ;

		void	set_useless( int n ) { useless = n; };
		int		get_useless( void ) { return this->useless; };
	
	private:

		Fixed const _x;
		Fixed const _y;
		int			useless;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
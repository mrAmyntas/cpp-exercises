#include "Point.hpp"

//CONSTRUCTORS - DESTRUCTOR
Point::Point( void ) : _x(0), _y(0), useless(3) {  }
Point::Point( const float f1, const float f2 ) : _x(f1), _y(f2) { }
Point::Point( Point const & src ) : _x(src.get_x()), _y(src.get_y()){ }
Point &	Point::operator=( Point const & rhs ) { this->useless = rhs.useless; return (*this); }
Point::~Point( void ) { }

//GET X/Y
Fixed   Point::get_x( void ) const { return (this->_x); }
Fixed   Point::get_y( void ) const { return (this->_y); }


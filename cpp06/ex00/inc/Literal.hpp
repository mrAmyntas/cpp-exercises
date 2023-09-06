#pragma once
#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <sstream>

class Literal;

typedef  void (Literal::*LiteralMemFn)( void );
#define CALL_MEMBER_FN(ptrToMember)  (this->*(ptrToMember))


class Literal {

	public:

		Literal( void );
		~Literal( void );
		Literal &	operator=( Literal const & rhs );
		Literal( Literal const & src );

		void 		detect_type(std::string str) ;
		void 		detect_number(std::string str) ;
		void		string_to_type(std::string str);
		void		cast_to_other_types( void );
		void		display_values( void );
	
		void		convert_from_char( void );
		void		convert_from_int( void );
		void		convert_from_float( void );
		void		convert_from_double( void );

	private:

		std::string	_type;
		std::string	_exception;
		int			_dot;
		int			_int_val;
		float		_float_val;
		char		_char_val;
		double		_double_val;
		bool		_int_range;
		bool		_float_range;
		bool		_scientific_notation;
};

#endif // CONVERT_HPP
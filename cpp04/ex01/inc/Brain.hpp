#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain {

	public:

		Brain( void );
		Brain( std::string str[100] );
		~Brain();
		Brain( Brain const & src );
		Brain & operator=( Brain const & rhs );

		std::string ideas[100];
};

#endif // BRAIN_HPP
#pragma once

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <unistd.h>

class Harl;

typedef  void (Harl::*HarlMemFn)( void );
#define CALL_MEMBER_FN(ptrToMember)  (this->*(ptrToMember))

class Harl {

	public:

		Harl();
		~Harl();

		void	complain( std::string level );

	private:
	
		void 	debug( void );
		void 	info( void );
		void 	warning( void );
		void	error( void );

};

#endif // HARL_H
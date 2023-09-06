#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Intern;

typedef  AForm* (Intern::*InternMemFn)( std::string form_target );
#define CALL_MEMBER_FN(ptrToMember)  (this->*(ptrToMember))

class Intern {

	public:

		Intern( void );
		~Intern( void );
		Intern &	operator=( Intern const & rhs );
		Intern( Intern const & src );

		AForm*	makeForm( std::string form_name, std::string form_target);
		AForm*	makePresForm( std::string form_target );
		AForm*	makeRobForm( std::string form_target );
		AForm*	makeShrubForm( std::string form_target );


	private:

		int	private_stuff;
};

#endif // INTERN_HPP

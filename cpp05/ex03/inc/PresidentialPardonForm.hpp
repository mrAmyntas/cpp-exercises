#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );

		virtual ~PresidentialPardonForm( void );
		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		
		std::ostream &			print(std::ostream& out, AForm & f) const;
		bool					execute(Bureaucrat const & executor) const;
		std::string 			getTarget( void ) const;

	private:

		std::string _target;
};


#endif // PRESIDENTIALPARDONFORM_HPP
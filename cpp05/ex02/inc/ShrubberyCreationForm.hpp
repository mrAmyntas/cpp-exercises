#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );

		virtual ~ShrubberyCreationForm( void );
		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		
		std::ostream &			print(std::ostream& out, AForm & f) const;
		bool					execute(Bureaucrat const & executor) const;
		std::string 			getTarget( void ) const;

	private:

		std::string _target;
};

void write_trees(std::ofstream & os);

#endif // SHRUBBERYCREATIONFORM_HPP
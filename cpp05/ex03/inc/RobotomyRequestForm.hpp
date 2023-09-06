#pragma once
#ifndef RobotomyRequestFORM_HPP
#define RobotomyRequestFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm {

	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );

		virtual ~RobotomyRequestForm( void );
		RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		
		std::ostream &			print(std::ostream& out, AForm & f) const;
		bool					execute(Bureaucrat const & executor) const;
		std::string 			getTarget( void ) const;

	private:

		std::string _target;
};


#endif // RobotomyRequestFORM_HPP
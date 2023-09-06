#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

	public:

		Bureaucrat( void );
		Bureaucrat( std::string str, int grade );

		~Bureaucrat( void );
		Bureaucrat &	operator=( Bureaucrat const & rhs );
		Bureaucrat( Bureaucrat const & src );

		int					getGrade( void ) const;
		const std::string	getName( void ) const;
		void				increment( void );
		void				decrement( void );
		void				signForm( Form & F);
	
		class GradeTooHighException : public std::exception {

			public:
				const char *what() const throw()
				{
					return ("Grade is too high");
				}

		};

		class GradeTooLowException : public std::exception {

			public:
			const char *what() const throw()
			{
				return ("Grade is too low");
			}
		};

	private:

		const std::string	_name;
		int					_grade;

};


void grade_range_test(int grade, std::string name);
std::ostream & operator<<( std::ostream & o, Bureaucrat & b);

#endif // BUREAUCRAT_HPP
#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:

		Form( void );
		Form( std::string str, int grade, int exec );

		~Form( void );
		Form &	operator=( Form const & rhs );
		Form( Form const & src );

		int					getSignrequirement( void ) const;
		int					getExecuterequirement( void ) const;
		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		int 				grade_bounds_test(int signreq, std::string name);
		bool				beSigned( Bureaucrat & A);

		class GradeTooHighException : public std::exception {

			public:
				const char *what() const throw()
				{
					return ("Requirement grade is too high");
				}

		};

		class GradeTooLowException : public std::exception {

			public:
				const char *what() const throw()
				{
					return ("Requirement grade is too low");
				}
		};

	private:

		const std::string 	_name;
		bool				_signed;
		const int			_sign_requirement;
		const int			_exec_requirement;

};

std::ostream & operator<<( std::ostream & o, Form & f);

#endif // FORM_HPP
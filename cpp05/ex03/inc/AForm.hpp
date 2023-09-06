#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:

		AForm( void );
		AForm( std::string str, int sign, int exec );

		virtual ~AForm( void );
		AForm &	operator=( AForm const & rhs );
		AForm( AForm const & src );

		virtual int					getSignrequirement( void ) const;
		virtual int					getExecrequirement( void ) const;
		virtual const std::string	getName( void ) const;
		virtual bool				getSigned( void ) const;
		virtual int 				grade_bounds_test(int gradereq, std::string name);
		virtual bool				beSigned( Bureaucrat & A);
		virtual bool				execute(Bureaucrat const & executor) const = 0;
		virtual std::ostream & 		print(std::ostream& out, AForm & f) const;
 
		class GradeTooHighException : public std::exception {

			public:
				const char *what() const throw()
				{
					return ("Grade requirement is too high");
				}

		};

		class GradeTooLowException : public std::exception {

			public:
			const char *what() const throw()
			{
				return ("Grade requirement is too low");
			}
		};

	private:

		const std::string 	_name;
		bool				_signed;
		const int			_sign_requirement;
		const int			_exec_requirement;

};

std::ostream & operator<<( std::ostream & o, AForm & f);

#endif // AFORM_HPP
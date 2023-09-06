#include "../inc/Form.hpp"

//CONSTRUCTORS
//DEFAULT
Form::Form( void ) : _name("Default form"),_signed(false), _sign_requirement(150), _exec_requirement(150) { };
//WITH STRING AND INT
Form::Form( std::string name, int gradereq, int exec ) : _name(name), _signed(false), _sign_requirement(gradereq), _exec_requirement(exec)
{ 
	grade_bounds_test(_sign_requirement, _name);
	grade_bounds_test(_exec_requirement, _name);
}
//COPY
Form::Form( Form const & src ) : _name(src.getName()), _sign_requirement(src.getSignrequirement()),  _exec_requirement(src.getExecuterequirement())
{
	grade_bounds_test(_sign_requirement, _name);
	grade_bounds_test(_exec_requirement, _name);
	*this = src;
}
//ASSIGNMENT =
Form & Form::operator=( Form const & src ) 
{
	if (this == &src)
		return (*this);
	_signed = src._signed;
	return (*this);
}
//DESTRUCTOR
Form::~Form( void ){ }
// << OVERLOAD
std::ostream & operator<<( std::ostream & o, Form & f)
{
	if (f.getSigned() == 0)
		o << "Form: " << f.getName() << ". Sign requirement: " << f.getSignrequirement() << ". Execute requirement: " << f.getExecuterequirement() << ". Status: Unsigned." << std::endl;
	else
		o << "Form: " << f.getName() << ". Sign requirement: " << f.getSignrequirement() << ". Execute requirement: " << f.getExecuterequirement() << ". Status: Signed." << std::endl;
	return o;
}

//GETTERS
int 				Form::getSignrequirement( void ) const { return _sign_requirement; }
const std::string	Form::getName( void ) const { return _name; }
bool 				Form::getSigned( void ) const { return _signed; }
int					Form::getExecuterequirement( void ) const { return _exec_requirement; }

//GRADE BOUNDS TEST
int Form::grade_bounds_test(int grade, std::string name)
{
	try
	{
		if (grade < 1)
			throw Form::GradeTooHighException();
		if (grade > 150)
			throw Form::GradeTooLowException();
	}	
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: Form " << name << ": Requirement is out of bounds: " << e.what() << ": " << grade <<'\n';
		return -1;
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << "Exception: Form " << name << ": Requirement is out of bounds: " << e.what() << ": " << grade <<'\n';
		return -1;
	}
	return 0;
}
//SIGN A FORM
bool	Form::beSigned( Bureaucrat & A )
{
	try
	{
		if (A.getGrade() <= this->getSignrequirement())
			this->_signed = true;
		else
			throw Form::GradeTooLowException();
	}
	catch (const Form::GradeTooLowException & e )
	{
		std::cerr	<< "Bureaucrat " << A.getName()
					<< " (" << A.getGrade() << ") " << "couldn't sign form "
					<< this->getName() << ", because he lacks the required grade ("
					<< this->getSignrequirement() << ")." << std::endl;
		return (false);
	}
	return (true);
}

#include "../inc/AForm.hpp"

//CONSTRUCTORS
//DEFAULT
AForm::AForm( void ) : _name("Default form"),_signed(false), _sign_requirement(150), _exec_requirement(150) { };
//WITH STRING AND INT
AForm::AForm( std::string name, int sign, int exec ) : _name(name), _signed(false), _sign_requirement(sign), _exec_requirement(exec)
{ 
	AForm::grade_bounds_test(_sign_requirement, _name);
	AForm::grade_bounds_test(_exec_requirement, _name);

}
//COPY
AForm::AForm( AForm const & src ) : _name(src.getName()), _sign_requirement(src.getSignrequirement()), _exec_requirement(src.getExecrequirement())
{
	AForm::grade_bounds_test(_sign_requirement, _name);
	AForm::grade_bounds_test(_exec_requirement, _name);
	*this = src;
}
//ASSIGNMENT =
AForm & AForm::operator=( AForm const & src ) 
{
	_signed = src._signed;
	return (*this);
}
//DESTRUCTOR
AForm::~AForm( void ){ }
// << OVERLOAD
std::ostream & operator<<( std::ostream & o, AForm & f)
{
	return (f.print(o, f));
	if (f.getSigned() == 0)
		o << "Form: " << f.getName() << ". Sign requirement: " << f.getSignrequirement() << ". Execute requirement: " << f.getExecrequirement() << ". Status: Unsigned." << std::endl;
	else
		o << "Form: " << f.getName() << ". Sign requirement: " << f.getSignrequirement() << ". Execute requirement: " << f.getExecrequirement() << ". Status: Signed." << std::endl;
	return o;
}
//PRINT FUNCTION
std::ostream & 		AForm::print(std::ostream& o, AForm & f) const
{
	if (f.getSigned() == 0)
		o << "Form: " << f.getName() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << " . Status: Unsigned." << std::endl;
	else
		o << "Form: " << f.getName() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << " . Status: Signed." << std::endl;
	return o;

}

//GETTERS
int 				AForm::getSignrequirement( void ) const { return _sign_requirement; }
const std::string	AForm::getName( void ) const { return _name; }
bool 				AForm::getSigned( void ) const { return _signed; }
int 				AForm::getExecrequirement( void ) const { return _exec_requirement; }
//GRADE BOUNDS TEST
int AForm::grade_bounds_test(int grade, std::string name)
{
	try
	{
		if (grade < 1)
			throw AForm::GradeTooHighException();
		if (grade > 150)
			throw AForm::GradeTooLowException();
	}	
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << "Exception: Form " << name << ": Grade requirement is out of bounds: " << e.what() << ": " << grade <<'\n';
		return -1;
	}
	catch(const AForm::GradeTooLowException & e)
	{
		std::cerr << "Exception: Form " << name << ": Grade requirement is out of bounds: " << e.what() << ": " << grade <<'\n';
		return -1;
	}
	return 0;
}
//SIGN A AFORM
bool AForm::beSigned( Bureaucrat & A )
{
	try
	{
		if (A.getGrade() <= this->getSignrequirement())
			this->_signed = true;
		else
			throw AForm::GradeTooLowException();
	}
	catch (const AForm::GradeTooLowException & e )
	{
		std::cerr	<< A.getName()
					<< " (" << A.getGrade() << ") " << "couldn't sign "
					<< this->getName() << ", because he lacks the required grade ("
					<< this->getSignrequirement() << ")." << std::endl;
		return (false);
	}
	return (true);
}

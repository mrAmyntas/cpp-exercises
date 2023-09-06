#include "../inc/PresidentialPardonForm.hpp"

//CONSTRUCTORS
//DEFAULT
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential Pardon Form", 25, 5), _target("pardontarget") { };
//WITH STRING
PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{ 
}
//COPY
PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm(src)
{
	*this = src;
}
//ASSIGNMENT =
PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & src ) 
{
	_target = src._target;
	return (*this);
}
//DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm( void ){ }
//PRINT FUNCTION
std::ostream & PresidentialPardonForm::print(std::ostream& o, AForm & f) const
{
	if (f.getSigned() == 0)
		o << f.getName() << " concerning " << this->getTarget() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << ". Status: Unsigned." << std::endl;
	else
		o << f.getName() << " concerning " << this->getTarget() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << ". Status: Signed." << std::endl;
	return o;

}
//GETTERS
std::string PresidentialPardonForm::getTarget( void ) const { return _target; }
//EXECUTE
bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " informs " << this->getTarget() << " that Zaphod Beeblebrox has pardoned them." << std::endl;
	return (true);
}

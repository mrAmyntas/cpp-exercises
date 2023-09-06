#include "../inc/RobotomyRequestForm.hpp"

//CONSTRUCTORS
//DEFAULT
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Robotomy Request Form", 72 , 45), _target("robotomy target")  { }
//WITH STRING
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robotomy Request Form", 72, 45), _target(target){ }
//COPY
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm(src){ *this = src; }
//ASSIGNMENT =
RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & src ) 
{
	_target = src._target;
	return (*this);
}
//DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm( void ){ }
//PRINT FUNCTION
std::ostream & RobotomyRequestForm::print(std::ostream& o, AForm & f) const
{
	if (f.getSigned() == 0)
		o << f.getName() << " concerning " << this->getTarget() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << ". Status: Unsigned." << std::endl;
	else
		o << f.getName() << " concerning " << this->getTarget() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << ". Status: Signed." << std::endl;
	return o;

}
//GETTERS
std::string RobotomyRequestForm::getTarget( void ) const { return _target; }
//EXECUTE
bool		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	//Makes some drilling noises. Then, informs that <target> has been robotomized
	//successfully 50% of the time. Otherwise, informs that the robotomy failed.
	int random;

	if (this->getSigned() == false)
		std::cout << executor.getName() << " can't execute " << this->getTarget() << "'s robotomy, because the form isn't signed." << std::endl;
	else if (executor.getGrade() > this->getExecrequirement())
		std::cout << executor.getName() << " can't execute " << this->getTarget() << "'s robotomy, because " << executor.getName() << "'s grade is too low." << std::endl;
	else
	{
		std::cout << "* DRILLING NOISES *" << std::endl;
		random = rand() % 2000;
		if (random < 1000)
		{
			std::cout << executor.getName() << " informs " << this->getTarget() << " that they were succesfully robotomized!" << std::endl;
			return (true);
		}
		else
			std::cout << executor.getName() << " informs " << this->getTarget() << " that the robotomy failed..." << std::endl;
	}
	return (false);
}

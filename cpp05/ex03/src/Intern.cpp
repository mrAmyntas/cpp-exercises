#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

//CONSTRUCTORS
//DEFAULT
Intern::Intern( void ) { };
//COPY
Intern::Intern( Intern const & src )
{ 
	*this = src;
}
//ASSIGNMENT =
Intern & Intern::operator=( Intern const & src ) 
{
	this->private_stuff = src.private_stuff;
	return (*this);
}
//DESTRUCTOR
Intern::~Intern( void ){ }
//MAKE A FORM
AForm*	Intern::makeForm( std::string form_name, std::string form_target)
{

	InternMemFn	fs[] = { &Intern::makePresForm, &Intern::makeRobForm, &Intern::makeShrubForm };
	std::string	s[] = { "presidential pardon", "robotomy request", "shrubbery creation" };

	for (int i = 0; i < 3; ++i)
	{
		if (form_name.compare(s[i]) == 0)
		{
			AForm *new_form = CALL_MEMBER_FN(fs[i])(form_target);
			std::cout << "Intern creates " << new_form->getName() << "." << std::endl;
			return (new_form);
		}
	}
	std::cout << "Intern could't create " << form_name << ", because it is not a legitimate form name." << std::endl;
	return 0;
}

AForm*	Intern::makePresForm( std::string form_target ) { return (new PresidentialPardonForm(form_target)); };
AForm*	Intern::makeRobForm( std::string form_target ) { return (new RobotomyRequestForm(form_target)); };
AForm*	Intern::makeShrubForm( std::string form_target ) { return (new ShrubberyCreationForm(form_target)); };

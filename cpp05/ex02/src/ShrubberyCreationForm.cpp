#include "../inc/ShrubberyCreationForm.hpp"

//CONSTRUCTORS
//DEFAULT
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Shrubbery Creation Form", 145, 137), _target("shrubbery target"){ };
//WITH STRING
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{ 
}
//COPY
ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src)
{
	*this = src;
}
//ASSIGNMENT =
ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & src ) 
{
	_target = src._target;
	return (*this);
}
//DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm( void ){ }
//PRINT FUNCTION
std::ostream & ShrubberyCreationForm::print(std::ostream& o, AForm & f) const
{
	if (f.getSigned() == 0)
		o << f.getName() << " concerning " << this->getTarget() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << ". Status: Unsigned." << std::endl;
	else
		o << f.getName() << " concerning " << this->getTarget() << ". Grade requirement: Sign:" << f.getSignrequirement() << " Exec:" << f.getExecrequirement() << ". Status: Signed." << std::endl;
	return o;

}
//GETTERS
std::string ShrubberyCreationForm::getTarget( void ) const { return _target; }
//EXECUTE
bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string newfilename = this->getTarget();
	newfilename = newfilename.append("_shrubbery");
	std::ofstream os (newfilename);
	if (!os)
	{
		std::cerr << executor.getName() << ": Error creating " << newfilename << std::endl;
		return (false);
	}
	write_trees(os);
	return (true);
}

//ASCII TREES
void write_trees(std::ofstream & os)
{
	
	os	<< "            ###\n         # ### ###	\n"
		<< "        # #### ####\n      ### \\/#|### |/####\n"     
		<< "     ##\\/#/ \\||/##/_/##/_#\n   ###  \\/###|/ \\/ # ###\n"
		<< " ##_\\_#\\_\\## | #/###_/_####\n## #### # \\ #| /  #### ##/##\n"
		<< " __#_--###`  |{,###---###-~\n           \\ }{\n            }}{\n"
		<< "            }}{\n            {{}\n      , -=-~{ .-^- _\n"
		<< "            `}\n             {\n";
	os	<< "\n\n            ###\n         # ### ###	\n"
		<< "        # #### ####\n      ### \\/#|### |/####\n"     
		<< "     ##\\/#/ \\||/##/_/##/_#\n   ###  \\/###|/ \\/ # ###\n"
		<< " ##_\\_#\\_\\## | #/###_/_####\n## #### # \\ #| /  #### ##/##\n"
		<< " __#_--###`  |{,###---###-~\n           \\ }{\n            }}{\n"
		<< "            }}{\n            {{}\n      , -=-~{ .-^- _\n"
		<< "            `}\n             {\n";

}

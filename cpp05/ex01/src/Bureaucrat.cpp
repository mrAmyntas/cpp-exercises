#include "../inc/Bureaucrat.hpp"

//CONSTRUCTORS
//DEFAULT
Bureaucrat::Bureaucrat( void ) : _name("Kafka"), _grade(150) { };
//WITH STRING AND INT
Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{ 
	grade_range_test(getGrade(), getName());
}
//COPY
Bureaucrat::Bureaucrat( Bureaucrat const & src )
{ 
	*this = src;
}

//ASSIGNMENT =
Bureaucrat & Bureaucrat::operator=( Bureaucrat const & src ) 
{
	this->_grade = src._grade;
	grade_range_test(getGrade(), getName());
	return (*this);
}
//DESTRUCTOR
Bureaucrat::~Bureaucrat( void ){ }
// << OVERLOAD
std::ostream & operator<<( std::ostream & o, Bureaucrat & b)
{
	o << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
	return o;
}
//GET 
const std::string	Bureaucrat::getName( void ) const { return (_name); }
int					Bureaucrat::getGrade( void ) const { return ( _grade ); }
// INCREMENT / DECREMENT
void Bureaucrat::increment( void )
{
	this->_grade--;
	grade_range_test(getGrade(), getName());

}
void Bureaucrat::decrement( void )
{
	this->_grade++;
	grade_range_test(getGrade(), getName());
}
//GRADE TEST
void grade_range_test(int grade, std::string name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}	
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: Bureaucrat: " << name << ": " << e.what() << ": " << grade <<'\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: Bureaucrat: " << name << ": " << e.what() << ": " << grade <<'\n';
	}
}
//SIGN A FORM
void Bureaucrat::signForm( Form & F )
{
	if (F.getSigned() == true)
	{
		std::cout	<< "Bureaucrat " << this->getName() << " couldn't sign form "
					<< F.getName() << ", because it has already been signed." << std::endl;
		return ;
	}
	if (F.grade_bounds_test(F.getSignrequirement(), F.getName()) == -1)
	{
		std::cout	<< "Bureaucrat " << this->getName() << " couldn't sign form "
					<< F.getName() << ", because it's required grade is out of bounds." << std::endl;
		return ;
	}
	if (F.beSigned(*this))
		std::cout << "Bureaucrat " << this->getName() << " signed form " << F.getName() << "." << std::endl;
}

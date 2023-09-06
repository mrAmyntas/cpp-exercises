#include "../inc/Bureaucrat.hpp"

//CONSTRUCTORS
//DEFAULT
Bureaucrat::Bureaucrat( void ) : _name("Kafka"), grade(150) { };
//WITH STRING AND INT
Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), grade(grade)
{ 
	grade_range_test(getGrade(), getName());
}
//COPY
Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	grade_range_test(src.getGrade(), src.getName());
	*this = src;
}

//ASSIGNMENT =
Bureaucrat & Bureaucrat::operator=( Bureaucrat const & src ) 
{
	if (this == &src)
		return (*this);
	this->grade = src.getGrade();
	return (*this);
}
//DESTRUCTOR
Bureaucrat::~Bureaucrat( void ){ std::cout << "B destructor" << std::endl; }
// << OVERLOAD
std::ostream & operator<<( std::ostream & o, Bureaucrat & b)
{
	o << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
	return o;
}
//GET 
const std::string	Bureaucrat::getName( void ) const { return (_name); }
int					Bureaucrat::getGrade( void ) const { return ( grade ); }
// INCREMENT / DECREMENT
void Bureaucrat::increment( void )
{
	if (grade_range_test(getGrade() - 1, getName()))
		this->grade--;
}
void Bureaucrat::decrement( void )
{
	if (grade_range_test(getGrade() + 1, getName()))
		this->grade++;
}
//GRADE TEST
bool grade_range_test(int grade, std::string name)
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
		return (false);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: Bureaucrat: " << name << ": " << e.what() << ": " << grade <<'\n';
		return (false);
	}
	return (true);
}
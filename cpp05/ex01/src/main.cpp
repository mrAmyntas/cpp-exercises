#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main ( void )
{
	Bureaucrat 	Ben("Ben", 11);
	Form		A("A", 10, 5);

	std::cout << Ben << A;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Trying to let Ben sign A..." << std::endl;
	std::cout << "---------------------------" << std::endl;
	Ben.signForm(A);
	std::cout << A;
	std::cout << "---------------------------" << std::endl;
	std::cout << "incrementing B so his grade is 10 and try signing again...(twice)" << std::endl;
	std::cout << "---------------------------" << std::endl;
	Ben.increment();
	Ben.signForm(A);
	Ben.signForm(A);
	std::cout << A;
	std::cout << "---------------------------" << std::endl;
	Form B("B", 151, 45);
	Form C("C", 45, 0);
	std::cout << B;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Trying to let Ben sign B..." << std::endl;
	std::cout << "---------------------------" << std::endl;
	Ben.signForm(B);
	std::cout << B;
	return 0;
}
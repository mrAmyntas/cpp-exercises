#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main ( void )
{
	Bureaucrat 	Ben("Ben", 1);
	Bureaucrat 	Ben2("Ben2", 150);

	AForm *A = new PresidentialPardonForm("Trump");
	AForm *B = new RobotomyRequestForm("Melania");
	AForm *C = new ShrubberyCreationForm("Codam");
	std::cout << *A << *B << *C << Ben;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Trying to let Ben sign A & B..." << std::endl;
	std::cout << "---------------------------" << std::endl;
	Ben.signForm(*A);
	Ben.signForm(*B);
	std::cout << *A << *B;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Trying to let Ben execute A..." << std::endl;
	std::cout << "---------------------------" << std::endl;
	Ben.executeForm(*A);
	std::cout << "---------------------------" << std::endl;
	std::cout << "Trying to let Ben execute B...(4x)" << std::endl;
	std::cout << "---------------------------" << std::endl;
	Ben.executeForm(*B);
	Ben.executeForm(*B);
	Ben.executeForm(*B);
	Ben.executeForm(*B);

	std::cout << "---------------------------" << std::endl;
	std::cout << "Trying to let Ben2 sign C..." << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << Ben2;
	Ben2.signForm(*C);
	Ben.executeForm(*C);
	std::cout << "---------------------------" << std::endl;
	std::cout << "Trying to let Ben sign and execute C..." << std::endl;
	std::cout << "---------------------------" << std::endl;
	Ben.signForm(*C);
	Ben2.executeForm(*C);
	Ben.executeForm(*C);

	return 0;
}
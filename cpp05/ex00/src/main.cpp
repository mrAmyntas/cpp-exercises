#include "../inc/Bureaucrat.hpp"

int main ( void )
{
	Bureaucrat Ben("Ben", 0);
	Bureaucrat Ben2("Ben2", 151);
	Bureaucrat Ben3("Ben3", 1);
	Bureaucrat Ben4("Ben4", -1);
	std::cout << "--------------" << std::endl;
	Ben3.increment();
	std::cout << Ben << Ben2 << Ben3 << Ben4;
	std::cout << "--------------" << std::endl;
	for (int i = 0; i < 150; ++i)
	{
		Ben3.decrement();
	}
	std::cout << "--------------" << std::endl;
	Bureaucrat Ben5(Ben4);
	Bureaucrat Ben6 = Ben4;
	return 0;
}
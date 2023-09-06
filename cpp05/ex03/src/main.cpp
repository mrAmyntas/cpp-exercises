#include "../inc/Intern.hpp"

int main ( void )
{

	Intern myIntern;
	AForm ** new_forms = new AForm*[5];

	new_forms[0] = myIntern.makeForm("presidential pardon", "Trump");
	new_forms[1] = myIntern.makeForm("robotomy request", "Melania");
	new_forms[2] = myIntern.makeForm("shrubbery creation", "Codam");
	new_forms[3] = myIntern.makeForm("presidential pardon", "OJ");
	new_forms[4] = myIntern.makeForm("get out of jail free", "Bob");

	for (int i = 0; i < 5; ++i)
	{
		if (new_forms[i] != 0)
			std::cout << *new_forms[i];
	}
	for (int i = 0; i < 5; ++i)
	{
		if (new_forms[i] != 0)
			delete new_forms[i];
	}
	delete [] new_forms;
	return 0;
}
#include "../inc/Harl.hpp"

int main(int ac, char **av)
{
	Harl Harl;
	
	if (ac != 2)
	{ std::cout << "program takes one and only one argument!\n"; return (0);}

	std::string level = av[1];
	Harl.complain(level);
	return (0);
}

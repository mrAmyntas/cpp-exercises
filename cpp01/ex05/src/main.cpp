#include "../inc/Harl.hpp"

int main(int ac, char **av)
{
	Harl Harl;

	if (ac == 1)
	{
		while (1)
		{
			Harl.complain("DEBUG");
			sleep(2);
			Harl.complain("ERROR");
			sleep(2);
			Harl.complain("WARNING");
			sleep(2);
			Harl.complain("INFO");
			sleep(2);
		}
	}
	for (int i = 1; i < ac; i++)
		Harl.complain(av[i]);
	return 0;
}

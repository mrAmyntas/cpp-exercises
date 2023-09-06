#include "../inc/Literal.hpp"

int main ( int ac, char **av )
{
	if (ac != 2)
	{
		std::cout << "program requires ONE argument" << std::endl;
		return -1;
	}
	std::string str = static_cast<std::string>(av[1]);
	Literal literal;

	literal.detect_type(str);
	literal.string_to_type(str);
	literal.cast_to_other_types();
	literal.display_values();
	return 0;
}
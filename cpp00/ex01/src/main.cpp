#include "../inc/PhoneBook.hpp"
#include <ctime>

int main(void)
{
	PhoneBook my_pb;
	std::string input = "NIET EXIT";

	std::cout << "WELCOME TO THE PHONEBOOK. IT IS EMPTY.\nTYPE \"ADD\" TO ADD CONTACTS\nTYPE \"SEARCH\" TO FIND CONTACT INFO.\nTYPE \"EXIT\" TO EXIT\n> ";
	while (input.compare("EXIT"))
	{
		std::getline (std::cin, input);
		if (input.compare("ADD") == 0)
			my_pb.add_contact();
		if (input.compare("SEARCH") == 0)
			my_pb.show_index();
		if (input.compare("EXIT"))
			std::cout << "> ENTER ADD/SEARCH/EXIT" << std::endl << "> ";
	}
	return (0);
}

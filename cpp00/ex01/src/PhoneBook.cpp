#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contact_num(1) {};
PhoneBook::~PhoneBook(void){};

//PHONEBOOK CLASS FUNCTIONS
//----------------------------------------------------------------

std::string	PhoneBook::truncate_string(std::string str){

	if (str.size() > 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	return (str);
};

void	PhoneBook::display_contact(void){

	std::string	input;

	std::cout << "PICK CONTACT NUMBER TO DISPLAY (OR ENTER RETURN FOR PREVIOUS MENU)\n> ";
	std::getline (std::cin, input);
	if (isdigit(input[0]) && input.size() == 1)
	{
		int a = std::stoi(input, NULL, 10);
		if (a == 0 || a > 8 || this->contact_array[a - 1].Contact::get_val("first_name").empty())
		{
			std::cout << "NO SUCH CONTACT EXISTS\n";
			display_contact();
		}
		else
		{
			std::cout	<< "---------------------------------------\n"
						<< "|   FIRST NAME    : " << this->contact_array[a - 1].Contact::get_val("first_name") << std::endl
						<< "|   LAST NAME     : " << this->contact_array[a - 1].Contact::get_val("last_name") << std::endl
						<< "|   NICKNAME      : " << this->contact_array[a - 1].Contact::get_val("nickname") << std::endl
						<< "|   PHONE NUMBER  : " << this->contact_array[a - 1].Contact::get_val("phone_number") << std::endl
						<< "|   DARKEST SECRET: " << this->contact_array[a - 1].Contact::get_val("secret") << std::endl
						<< "---------------------------------------\n";
		}
	}
	else if (input.compare("RETURN") == 0)
		return ;
	else
	{
		std::cout << "NO SUCH CONTACT EXISTS\n";
		display_contact();
	}
};

void	PhoneBook::show_index(void){
	
	std::string str;
	int	i = 0;

	str = this->contact_array[i].Contact::get_val("first_name");
	if (str.empty())
	{
		std::cout << "NO CONTACTS AVAILABLE\n";
		return ;
	}
	while (i < 8)
	{
		str = this->contact_array[i].Contact::get_val("first_name");
		if (!str.empty())
		{
			if (i == 0)
				std::cout << "|     index|first name| last name|  nickname|" << std::endl;
			std::cout	<< "|" << std::right << std::setw(10) << i + 1
						<< "|" << std::right << std::setw(10) 
						<< truncate_string(this->contact_array[i].Contact::get_val("first_name"))
						<< "|" << std::right << std::setw(10) 
						<< truncate_string(this->contact_array[i].Contact::get_val("last_name"))
						<< "|" << std::right << std::setw(10) 
						<< truncate_string(this->contact_array[i].Contact::get_val("nickname"))
						<< "|" << std::endl;
		}
		i++;
	}
	display_contact();
};

void	PhoneBook::add_contact_2(std::string msg, std::string val){

	std::string		input;
	unsigned long	i = 0;
	
	std::cout << "ADDING CONTACT> " << msg << ": ";
	std::getline (std::cin, input);
	while (input[i] == ' ')
		i++;
	while (input.empty() || i == input.size())
	{
		std::cout << "> " << msg << " (CAN'T BE EMPTY): ";
		std::getline (std::cin, input);
		i = 0;
		while (input[i] == ' ')
			i++;
	}
	this->contact_array[this->contact_num - 1].Contact::set_val(input, val);
};

void	PhoneBook::add_contact(void){
	
	std::string input;
	if (this->contact_num == 9)
		this->contact_num = 1;
	add_contact_2("ENTER FIRST NAME", "first_name");
	add_contact_2("ENTER LAST NAME", "last_name");
	add_contact_2("ENTER NICKNAME", "nickname");
	add_contact_2("ENTER PHONE NUMBER", "phone_number");
	add_contact_2("ENTER DARKEST SECRET", "secret");
	std::cout	<< "> CONTACT " << this->contact_array[this->contact_num - 1].Contact::get_val("first_name")
				<< "(" << this->contact_num << ")" << " SUCCESFULLY ADDED: " << std::endl;
	this->contact_num++;
};

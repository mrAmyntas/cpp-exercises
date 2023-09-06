#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook{

public:

	void	add_contact(void);
	void	show_index(void);

	PhoneBook(void);
	~PhoneBook(void);
	PhoneBook(const PhoneBook &old_PhoneBook);
	PhoneBook & operator = (const PhoneBook &old_PhoneBook);

private:

	class Contact{

		public:

			void		set_val(std::string input, std::string val);
			std::string	get_val(std::string val);

			Contact(void);
			~Contact(void);
			Contact(const Contact &old_Contact);
			Contact & operator = (const Contact &old_Contact);

		private:

			std::string	first_name;
			std::string	last_name;
			std::string	nickname;
			std::string	phone_number;
			std::string	secret;
	};

	Contact		contact_array[8];
	int			contact_num;

	void		display_contact(void);
	void		add_contact_2(std::string msg, std::string val);
	std::string	truncate_string(std::string str);

};

#endif
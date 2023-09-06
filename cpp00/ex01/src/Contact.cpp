/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 16:42:39 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/03/23 17:12:45 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::Contact::Contact(void) : first_name(""), last_name(""), nickname(""), phone_number(""), secret(""){};
PhoneBook::Contact::~Contact(void){};

//CONTACT CLASS FUNCTIONS
//----------------------------------------------------------------
std::string	PhoneBook::Contact::get_val(std::string val){
	
	if (val.compare("first_name") == 0)
		return (this->first_name);
	if (val.compare("last_name") == 0)
		return (this->last_name);
	if (val.compare("nickname") == 0)
		return (this->nickname);
	if (val.compare("phone_number") == 0)
		return (this->phone_number);
	return (this->secret);
};

void PhoneBook::Contact::set_val(std::string input, std::string val){
	
	if (val.compare("first_name") == 0)
		this->first_name = input;
	else if (val.compare("last_name") == 0)
		this->last_name = input;
	else if (val.compare("nickname") == 0)
		this->nickname = input;
	else if (val.compare("phone_number") == 0)
		this->phone_number = input;
	else
		this->secret = input;
};

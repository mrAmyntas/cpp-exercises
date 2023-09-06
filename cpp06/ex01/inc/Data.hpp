#pragma once
#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

typedef struct	Data 
{
	int			a;
	std::string	str1;
	double		d;
} 				Data;			

Data* deserialize(uintptr_t raw);
uintptr_t serialize(Data* ptr);

#endif // DATA_HPP
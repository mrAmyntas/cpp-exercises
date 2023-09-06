#include "../inc/Literal.hpp"
#include <cmath>
#include <float.h>

//CONSTRUCTORS
//DEFAULT
Literal::Literal( void ) : _type("void"), _exception("void"), _dot(0), _int_range(true), _float_range(true), _scientific_notation(false) { };
//COPY
Literal::Literal( Literal const & src )
{
	*this = src;
}
//ASSIGNMENT =
Literal & Literal::operator=( Literal const & src ) 
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}
//DESTRUCTOR
Literal::~Literal( void ){ }

//DETECT TYPES
void Literal::detect_number(std::string str)
{
	if (!str[1])
		this->_type = "int";
	else
	{
		for (int i = 0; str[i]; ++i) {
			if ((str[i] >= '0' && str[i] <= '9') || (i == 0 && str[i] == '-'))
				continue ;
			else
			{
				if (str[i] == 'f')
				{
					if (str[i + 1] != '\0')
					{
						std::cout << "illegal input: a float ends with one f" << std::endl;
						exit (-1);
					}
					else
						this->_type = "float";
				}
				else if (str[i] == '.')
				{
					this->_dot = 1;
					if (this->_type.compare("double") == 0)
					{
						std::cout << "illegal input: cant have multiple decimal points" << std::endl;
						exit (-1);
					}
					if (str[i + 1] == '\0' || str[i + 1] == 'f')
					{
						std::cout << "illegal input: require a number after a decimal point" << std::endl;
						exit (-1);
					}
					this->_type = "double";
				}
				else
				{
					std::cout << "illegal input: illegal character somewhere in a literal number string" << std::endl;
					exit (-1);
				}
			}
		}
		if (this->_type.compare("void") == 0)
			this->_type = "int";
	}
}

void Literal::detect_type(std::string str)
{
    std::string exceptions[6] = { "+inf", "-inf", "nan", "-inff", "+inff", "nanf" };

	if (str[0] < 32 || str[0] > 126) 													//under 32 and above 126 are nonprintable chars
	{
		std::cout << "illegal input: no nonprintable character" << std::endl;
		exit(-1);
	}
	else if ((str[0] >= 32 && str[0] < '0') || (str[0] > '9' && str[0] < 127)) 			//first literal char is printable but not a number (0-9)
	{
		for (int i = 0; i < 6; ++i) {                  									//tests for cases where it the literal is not a number but it should be interpreted as one, e.g. +inf
			if (str.compare(exceptions[i]) == 0)
			{
				if (i < 3)
					this->_type = "double";
				else
					this->_type = "float";
				this->_exception = exceptions[i];
				return ;
			}
		}
		if (str[0] == '-' && (str[1] >= '0' && str[1] <= '9'))
		{
			detect_number(str);
			return ;
		}
		if (str[1])
		{
			std::cout << "illegal input: should be one character not multiple" << std::endl;
			exit(-1);
		}
		this->_type = "char";
	}
	else																				//starts with a number
		detect_number(str);
	return ;
}

//CONVERT STRING TO TYPE
void	Literal::string_to_type(std::string str)
{
	std::stringstream	ss;															
	double				size;

	try 
	{
    	size = std::stod(str);
	}
	catch (std::out_of_range oor)
	{
		std::cout << "Error: invalid input (overflow)\n";
		exit (-1);
	}
	catch (std::invalid_argument ia)
	{
		//just ignoring this 
	}
	if (size > INT_MAX || size < INT_MIN)
		this->_int_range = false;
	if (size > FLT_MAX || (size * -1) > FLT_MAX)
		this->_float_range = false;
	if (size > 999999 || size < -99999)
		this->_scientific_notation = true;
	ss << str;
	if (this->_type.compare("char") == 0)
		ss >> this->_char_val;
	else if ((this->_type.compare("int") == 0))
		ss >> this->_int_val;
	else if ((this->_type.compare("float") == 0))
		this->_float_val = std::stof(str);
	else if ((this->_type.compare("double") == 0))
		ss >> this->_double_val;
}

//CAST TO OTHER TYPES
void	Literal::cast_to_other_types( void )
{
	LiteralMemFn	fs[] = { &Literal::convert_from_char, &Literal::convert_from_int, &Literal::convert_from_double, &Literal::convert_from_float };
	std::string 	types[4] = {"char", "int", "double", "float"};
	
	for (int i = 0; i < 4; ++i) {
		if (this->_type.compare(types[i]) == 0)
			CALL_MEMBER_FN(fs[i])();
	}
	if (this->_double_val == this->_int_val)
		this->_dot = 0;
}

void		Literal::convert_from_char( void )
{
	this->_double_val = static_cast<double>(this->_char_val);
	this->_float_val = static_cast<float>(this->_char_val);
	this->_int_val = static_cast<int>(this->_char_val);
}

void		Literal::convert_from_int( void )
{
	this->_double_val = static_cast<double>(this->_int_val);
	this->_float_val = static_cast<float>(this->_int_val);
	this->_char_val = static_cast<char>(this->_int_val);
}

void		Literal::convert_from_float( void )
{
	this->_double_val = static_cast<double>(this->_float_val);
	this->_int_val = static_cast<int>(this->_float_val);
	this->_char_val = static_cast<char>(this->_float_val);
}

void		Literal::convert_from_double( void )
{
	this->_float_val = static_cast<float>(this->_double_val);
	this->_int_val = static_cast<int>(this->_double_val);
	this->_char_val = static_cast<char>(this->_double_val);
}

void		Literal::display_values( void )
{
	if (_int_range == false || this->_exception.compare("void") != 0)
		std::cout 	<< "char: impossible" << std::endl;
	else if (this->_int_val < 32 || this->_int_val > 126)
		std::cout 	<< "char: Non displayable" << std::endl;
	else
		std::cout 	<< "char: '" << this->_char_val << "'" << std::endl;
	if (_int_range == false || this->_exception.compare("void") != 0)
		std::cout 	<< "int: impossible" << std::endl;
	else
		std::cout	<< "int: " << this->_int_val << std::endl;
	if (_float_range == false && this->_exception.compare("void") == 0)
		std::cout	<< "float: impossible" << std::endl;
	else if (this->_dot == 0 && this->_exception.compare("void") == 0 && this->_scientific_notation == false)
		std::cout 	<< "float: " << this->_float_val << ".0f" << std::endl;
	else
		std::cout 	<< "float: " << this->_float_val << "f" << std::endl;
	if (this->_dot == 0 && this->_exception.compare("void") == 0 && this->_scientific_notation == false)
		std::cout 	<< "double: " << this->_double_val << ".0" << std::endl;
	else
		std::cout 	<< "double: " << this->_double_val << std::endl;
}

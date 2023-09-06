#include "../inc/Harl.hpp"

//CONSTRUTOR DESTRUCTOR
Harl::Harl(){ };
Harl::~Harl(){ };

//USE LEVEL TO CALL CORRECT FUNCTION 
void Harl::complain( std::string level )
{
	HarlMemFn	fs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	s[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(s[i]))
			CALL_MEMBER_FN(fs[i])();
	}
}

//DIFFERENT LEVEL FUNCTIONS
void Harl::debug( void ){ std::cout<<"[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n"; }
void Harl::info( void ){ std::cout<<"[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n\n"; }
void Harl::warning( void ){ std::cout<<"[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n\n"; }
void Harl::error( void ){ std::cout<<"[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n\n"; }

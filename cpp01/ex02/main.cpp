#include <iostream>

int	main(void){

	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	std::cout	<< "------------------------------------------\n"
				<< "memory address of str      : "	<< &str 		<< std::endl
				<< "memory address of stringPTR: " 	<< stringPTR	<< std::endl
				<< "memory address of stringREF: " 	<< &stringREF	<< std::endl
				<< "------------------------------------------\n"
				<< "value of str           : " 		<< str 			<< std::endl
				<< "value pointed to by PTR: " 		<< *stringPTR 	<< std::endl
				<< "value pointed to by REF: " 		<< stringREF 	<< std::endl
				<< "------------------------------------------\n";

	return(0);
}

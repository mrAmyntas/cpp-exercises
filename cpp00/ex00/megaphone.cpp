/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 15:16:34 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/03/09 16:24:42 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <iomanip>

int	main(int ac, char **av){

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string input;
	for (int i = 1; i < ac; i++)
	{
		if (i > 1)
			input = input.append(" ");
		input = input.append(av[i]);
	}
	for (int i = 0; input[i]; i++)
		if (islower(input[i]))
			input[i] = toupper(input[i]);
	std::cout << input << std::endl;
	return (0);
}

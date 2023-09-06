#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	//input error check
	if (ac != 4)
	{
		std::cout << "Requires 3 arguments\n";
		return (1);
	}
	std::string arg2 = av[2];
	std::string arg3 = av[3];

	//opening file
	std::ifstream is (av[1], std::ifstream::in);
 	if (!is)
	{
		std::cerr << "Error opening " << av[1] << std::endl;
		return (1);
	}
	//make new file
	std::string newfilename;
	newfilename = newfilename.append(av[1]);
	newfilename = newfilename.append(".replace");
	std::ofstream os (newfilename);
	if (!os)
	{
		std::cerr << "Error creating " << newfilename << std::endl;
		return (1);
	}
	//copy content from file to new file
	std::string buff;
	while (getline(is, buff))
	{
		//find arg2 occurence in buff
		std::size_t found = buff.find(arg2);
		if (found!=std::string::npos) //if it finds a match -> replace with erase+insert
		{
			std::size_t len = arg2.length();
			buff.erase(found, len); //erases from position 'found' for size_t 'len'
			buff.insert(found, arg3); //inserts arg3 at position 'found'
		}
		os << buff << std::endl; //write buff (with replaced text if it matched) into os (.replace file)
	}
	is.close();
	os.close();
	return 0;
}

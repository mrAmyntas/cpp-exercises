#include "../inc/Data.hpp"

int	main(void)
{
	Data 		g;
	uintptr_t	ret = 0;

	g.a = 3;
	g.str1 = "hello";
	g.d = 2.5;

	std::cout << "before serialize:\na: " << g.a << "\nstr1: "<< g.str1 << "\nd: " << g.d << std::endl;
	std::cout << "serializing...\n";
	ret = serialize(&g);
	std::cout << "deserializing...\n";
	Data *h = deserialize(ret);
	std::cout << "after deserialize:\na: " << h->a << "\nstr1: "<< h->str1 << "\nd: " << h->d << std::endl;
	return 0;
}

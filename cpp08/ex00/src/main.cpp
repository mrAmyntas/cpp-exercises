#include "../inc/easyfind.tpp"

int main (void)
{
	{
		std::vector<int>			vect;
		std::vector<int>::iterator	it;

		vect.push_back(-1);
		vect.push_back(4);
		vect.push_back(8);
		vect.push_back(2);
		vect.push_back(0);
		for(int y = 0; y < 10; y += 2)
		{
			it = easyfind(vect, y);
			if (it == vect.end())
				std::cout << "did not find: " << y << std::endl;
			else
				std::cout << "found: " << y << " at index: " << (it - vect.begin()) << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::list<int>				l;
		std::list<int>::iterator	it;
	
		l.push_back(5);
		l.push_back(4);
		l.push_back(3);
		l.push_back(2);
		l.push_back(1);

		for(int y = 0; y < 10; y += 2)
		{
			it = easyfind(l, y);
			if (it == l.end())
				std::cout << "did not find: " << y << std::endl;
			else
				std::cout << "found: " << y << std::endl;
		}
	}
	return 0;
}

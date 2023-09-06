#include <iostream>
#include <dirent.h>


class A {

	public:
		A( ) : info(3) { };
		~A( ) { std::cout << "destructor called\n"; };
		int info;
		void dosmth( void );
};

class E : public std::exception {

	public:
		virtual const char *what() const throw()
		{
			return ("didnt open");
		}

};

void A::dosmth( void )
{
	this->info--;	
}

void deleteptr(A * &Aptr)
{
	delete Aptr;
	Aptr = 0;
}

void test1()
{
	DIR  *dir = NULL;

	dir = opendir("bestaatniet");
	if (dir == NULL)
		throw E();
}
int main (void)
{
	A *b = new A;

	std::cout << b->info << std::endl;

	deleteptr(b);
	if (b == 0)
		std::cout << "hoi\n";

	try
	{
		test1();
	}
	catch(const E& e)
	{
		std::cerr << "caught E" << '\n';
		std::cerr << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "caught e" << '\n';
		std::cerr << e.what() << '\n';
	}

	catch(int x)
	{
		std::cerr << "caught u" << '\n';
	}

	return 0;
}

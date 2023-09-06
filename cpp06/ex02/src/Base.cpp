#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base	*generate( void )
{
	int random;

	random = rand() % 3;
	if (random == 0)
	{
		try
		{
			A *a = new class A;
			Base *ptr = a;
			std::cout << "Made Base pointer of class A object!\n";
			return (ptr);
		}
		catch(std::bad_alloc& e)
		{
			std::cerr << e.what() << '\n';
			exit (-1);
		}
	}
	else if (random == 1)
	{
		try
		{
			B *b = new class B;
			Base *ptr = b;
			std::cout << "Made Base pointer of class B object!\n";
			return (ptr);
		}
		catch(std::bad_alloc& e)
		{
			std::cerr << e.what() << '\n';
			exit (-1);
		}
	}
	else if (random == 2)
	{
		try
		{
			C *c = new class C;
			Base *ptr = c;
			std::cout << "Made Base pointer of class C object!\n";
			return (ptr);
		}
		catch(std::bad_alloc& e)
		{
			std::cerr << e.what() << '\n';
			exit (-1);
		}
	}
	std::cout << "Made nothing of value!\n";
	return (NULL);
}

void	identify(Base* p)
{
	if (p == nullptr)
	{
		std::cout << "passed nullptr to identify function\n";
		return ;
	}
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "type of object is A!\n";
	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "type of object is B!\n";
	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "type of object is C!\n";
}
void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		A x = a; //to silence unused variable warning
	}
	catch (std::bad_cast bc)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			B x = b;
		}
		catch (std::bad_cast bc)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				C x = c;
			}
			catch (std::bad_cast bc)
			{
				std::cout << "A, B, nor C??\n";
			}
			std::cout << "type of object is C!\n";
			return ;
		}
		std::cout << "type of object is B!\n";
		return ;
	}
	std::cout << "type of object is A!\n";
}

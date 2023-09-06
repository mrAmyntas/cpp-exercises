#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main( void )
{
	// Animal A;
	// Animal *A = new Animal();

	Animal *A = new Dog();
	delete A;
	return (0);
}

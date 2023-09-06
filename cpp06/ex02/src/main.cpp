#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

//generate will instantiate an object of type A, B or C randomly and return it as a pointer to the Base class (all 3 are empty classes publically inheriting from Base)
//the identify functions will then find which type of object it is using the behavior of dynamic casts
int	main( void )
{
	Base *ptr;
	int	i = 0;

  	srand ( time(NULL) );
	while (i < 10)
	{
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
		i++;
	}
}

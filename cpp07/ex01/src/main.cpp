#include "../inc/iter.hpp"
#include <stdlib.h>

//iter functions takes an array of whatever and iterates a function over all elements
//print simply prints out the elements
//add does +1 to the value of the element
int main ( void )
{
	// size_t len = 4;
	// std::string arr1[4] = {"Hello", "this", "is", "dog"};
	// bool arr2[4] = {true, false, true, false};
	int arr3[4] = {0, 1, 2, 3};
	int *arr4[4] = {&arr3[0], &arr3[1], &arr3[2], &arr3[3]};	

	/*
	::iter(arr1, len, &print);
	std::cout << std::endl;
	::iter(arr2, len, &print);
	std::cout << std::endl;

	::iter(arr3, len, &print);
	std::cout << std::endl;
	::iter(arr4, len, &add);
	::iter(arr3, len, &print);
	*/
	int *x = nullptr;
	::iter(x, 2, &print);
	::iter(arr4, 2, &add);

	return 0;
}

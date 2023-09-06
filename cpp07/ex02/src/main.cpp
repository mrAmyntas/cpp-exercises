#include "../inc/Array.hpp"

//Array is a template class which can take an array of any type and set its elements to specific values with the setElem function
//the [] operator is overloaded so you can access the elements 
int	main( void )
{
	unsigned int n = 3;
	try
	{
		Array< float >  floatArray(n);
		floatArray.setElem(0,1.1);
		floatArray.setElem(1,2.3);
		floatArray.setElem(2,3.98);
		std::cout << "floatArray: [" << floatArray[0] << "," << floatArray[1] << "," << floatArray[2] << "]" << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array< std::string >  stringArray(n);
		stringArray.setElem(0,"hello");
		stringArray.setElem(1,"this works?");
		stringArray.setElem(2,"cool");
		std::cout << "floatArray: [" << stringArray[0] << "," << stringArray[1] << "," << stringArray[2] << "]" << std::endl << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<>	x;
		Array<>	y( n );
		Array<>	z( y );
		Array<> q = z;
		q = y;

		std::cout << z[0] << std::endl;
		std::cout << y[0] << std::endl;

		z.setElem(0, 2);
	
		std::cout << z[0] << std::endl;
		std::cout << y[0] << std::endl << std::endl;
		
		std::cout << "array y has size of: " << y.size() << std::endl;
		std::cout << "setting ele 0 of array y to 1.. " << std::endl << std::endl;
		y.setElem(0,1);
		std::cout << "setting ele 1 of array y to 2.. " << std::endl << std::endl;
		y.setElem(1,2);
		std::cout << "setting ele 2 of array y to 10.. " << std::endl << std::endl;
		y.setElem(2,10);
		std::cout << "setting ele 3 of array y to 12.. " << std::endl << std::endl;
		y.setElem(3,12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<>	y( n );
		y.setElem(0,1);
		y.setElem(1,1);
		y.setElem(2,1);

		std::cout << "y[0]: " << y[0] << std::endl; 
		std::cout << "y[1]: " << y[1] << std::endl; 
		std::cout << "y[2]: " << y[2] << std::endl; 
		std::cout << "y[3]: " << y[3] << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}


// #include <iostream>
// #include "../inc/Array.hpp"

// #define MAX_VAL 10
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
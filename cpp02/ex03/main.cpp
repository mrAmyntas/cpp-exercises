#include <iostream>
#include "Point.hpp"


int main( void )
{
	Point const a(0.0f, 0.0f);
	Point const b(0.0f, 3.0f);
	Point const c(5.0f, 0.0f);
	/*
		the line between b and c will go through point (1.69f,1.99f)
		the inside of the triangle is to the left and below.
		so (1.69f,1.99f) should be false (but isnt with _bits set at 8, with 9 it is precise enough)
		(1.69f,1.98f) and (1.68f,1.99f) should be true
		(1.70f,1.99f) and (1.69f,2.00f) should be false
	*/
	{
		
		Point const point(1.69f, 1.99f);
		if (bsp(a, b, c, point))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	{
		
		Point const point(1.68f, 1.99f);
		if (bsp(a, b, c, point))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	{
		
		Point const point(1.69f, 1.98f);
		if (bsp(a, b, c, point))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	{
		
		Point const point(1.70f, 1.99f);
		if (bsp(a, b, c, point))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	{
		
		Point const point(1.69f, 2.00f);
		if (bsp(a, b, c, point))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	//shows when it starts and stops being true
	//triangle interection points are (2.0 , 0.0) and (2.0 , 1.8)
	//increment with less than 0.1f to be more accurate
	int i = 0;
	float a1 = -1.0f;
	while (a1 < 3.0f)
	{
		Point const point(2.0f, a1);
		if (bsp(a, b, c, point))
		{
			//std::cout << "x: " << point.get_x() << " y: "<< point.get_y() << std::endl;
		}
		a1 = a1 + 0.00001f;
		i++;
	}
	return 0;
}

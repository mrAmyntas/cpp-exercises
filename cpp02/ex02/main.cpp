#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	
	Fixed a(2);
	Fixed b(3.5f);
	Fixed c = a + b;
	Fixed d(a + b);
	Fixed e(d);

	std::cout<< "a: " << a << std::endl;
	std::cout<< "b: " << b << std::endl;
	std::cout<< "c: " << c << std::endl;
	std::cout<< "d: " << d << std::endl;
	std::cout<< "e: " << e << std::endl;
	c = 5.5f;
	d = 2;
	e = 1;
	std::cout << "setting c->5.5f, d->2, e->1" << std::endl;
	std::cout<< "a: " << a << std::endl;
	std::cout<< "b: " << b << std::endl;
	std::cout<< "c: " << c << std::endl;
	std::cout<< "d: " << d << std::endl;
	std::cout<< "e: " << e << std::endl;

	std::cout<< "2 + 3.5f: " << a + b << std::endl;
	std::cout<< "2 - 3.5f: " << a - b << std::endl;
	std::cout<< "2 * 3.5f: " << a * b << std::endl;
	std::cout<< "2 / 3.5f: " << a / b << std::endl;


	std::cout << "a=" << a << " b=" << b << std::endl;
	std::cout<< "a > b: " << (a > b) << std::endl;
	std::cout<< "a < b: " << (a < b) << std::endl;
	std::cout<< "a >= b: " << (a >= b) << std::endl;
	std::cout<< "a <= b: " << (a <= b) << std::endl;
	std::cout<< "a == b: " << (a == b) << std::endl;
	std::cout<< "a != b: " << (a != b) << std::endl;

	Fixed x(3.021f);
	Fixed y(3.022f);
	Fixed z(3.023f);
	std::cout<< "x = " << x.getRawBits() << std::endl;
	std::cout<< "y = " << y.getRawBits() << std::endl;
	std::cout<< "z = " << z.getRawBits() << std::endl;
	if (y == x)
		std::cout<< "WRONG" << std::endl;
	if (a > b)
		std::cout << "oeps\n";
	if (b > a)
		std::cout << "whee\n";
	a = 3;
	std::cout<< "a = " << a << std::endl;
	a++;
	std::cout<< "a++: " << a << std::endl;
	a--;
	std::cout<< "a--: " << a << std::endl;
	b = a++;
	std::cout<< "a:" << a << " b:" << b << std::endl;

	Fixed const h( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout<< "h: " << h << std::endl;
	std::cout << "max(a, h): " << Fixed::max(a, h) << std::endl;
	std::cout << "min(a, h): " << Fixed::min(a, h) << std::endl;

	return 0;
}

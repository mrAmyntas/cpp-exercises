#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <iomanip>

template <class T>
void	print(T const ele)
{
	std::cout << "element is: " << ele << std::endl;
}

template<class T>
void add(T *x)
{
	if (x)
		*x = *x + 1;
}

template <class T>
void	iter(T *a, size_t const len, void (*f)(T ele))
{
	if (a)
	{
		for(size_t i = 0; i < len; ++i)
			f(a[i]);
	}
}

#endif // ITER_HPP
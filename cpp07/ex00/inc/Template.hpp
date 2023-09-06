#pragma once
#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <class myType>
myType	max (myType const a, myType const b)
{
	return (a > b ? a : b);
}

template <class myType>
myType	min (myType const a, myType const b)
{
	return (a < b ? a : b);
}
	
template <class myType>
void	swap (myType &a, myType &b)
{
	myType store;

	store = a;
	a = b;
	b = store;
}

#endif // TEMPLATE_HPP
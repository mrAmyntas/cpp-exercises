#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template < typename T >
typename T::iterator	easyfind( T &haystack, int needle )
{
	return find(haystack.begin(), haystack.end(), needle);
}

#endif //EASYFIND_TPP
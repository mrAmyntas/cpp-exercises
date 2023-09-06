#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack():std::stack<T>(){ }

template< typename T>
MutantStack<T>::~MutantStack() { }

template< typename T>
MutantStack<T>::MutantStack( MutantStack<T> const & src )
{
	*this = src;
}

template< typename T>
MutantStack<T> & MutantStack<T>::operator=( MutantStack<T> const & src )
{ 
	this->c = src.c;
	return *this;
}

// ITERATOR FUNCTIONS
template< typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template< typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{ 
	return this->c.end();
}

template< typename T>
typename MutantStack<T>::r_iterator MutantStack<T>::rbegin()
{ 
	return this->c.rbegin();
}

template< typename T>
typename MutantStack<T>::r_iterator MutantStack<T>::rend()
{ 
	return this->c.rend();
}

template< typename T>
typename MutantStack<T>::c_iterator MutantStack<T>::cbegin() const
{ 
	return this->c.cbegin();
}

template< typename T>
typename MutantStack<T>::c_iterator MutantStack<T>::cend() const
{ 
	return this->c.cend();
}

template< typename T>
typename MutantStack<T>::c_r_iterator MutantStack<T>::crbegin () const
{ 
	return this->c.crbegin();
}

template< typename T>
typename MutantStack<T>::c_r_iterator MutantStack<T>::crend() const
{ 
	return this->c.crend();
}

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T = int>
class Array {

	public:
		Array<T>( void ) : _elem(nullptr), _len(0)	{};				//Default contructor
		Array<T>( unsigned int n ) : _elem(nullptr), _len(n)		//Unsigned int constructor
		{
			try
			{
				this->_elem = new T[n];
			}
			catch(std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
				exit(-1);
			}
		}
		Array( Array const & src )									//copy constructor
		{
			try
			{
				this->_elem = new T[src._len];
				*this = src;
			}
			catch(std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
				exit(-1);
			}
		}
		Array &	operator=( Array const & src )						//assignment operator
		{
			if (this == &src)
				return (*this);
			this->_len = src._len;
			for (unsigned int i = 0; i < this->_len; ++i)
				this->_elem[i] = src._elem[i];
			return (*this);
		}
		~Array<T>()													//destructor
		{ 
			if (this->_len > 0)
				delete[] _elem;
		}
		T&	operator[](unsigned int const i)						//[] overload
		{
			if (this->_len <= i)
				throw Array::OutOfBoundsException();
			return this->_elem[i];
		}
		unsigned int	size( void ) const { return this->_len; }		//GET SIZE
		void			setElem( unsigned int const n, T const newval )	//SET AN ELEM OF ARRAY TO A VALUE
		{
			if (this->_len <= n)
				throw Array::OutOfBoundsException();
			this->_elem[n] = newval;
		}
		class OutOfBoundsException : public std::exception {		//CUSTEM EXCEPTION

			public:
				const char *what() const throw()
				{
					return ("Out of Bounds");
				}
		};

	private:
		T			*	_elem;
		unsigned int	_len;
};

#endif // ARRAY_HPP	
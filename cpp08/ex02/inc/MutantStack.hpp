#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <deque>

template< class T >
class MutantStack : public std::stack< T > {

	public:

		MutantStack();
		~MutantStack();
		MutantStack( MutantStack const & src );
		MutantStack & operator=( MutantStack const & src);

		typedef typename std::stack<T>::container_type::iterator 				iterator;
		typedef typename std::stack<T>::container_type::const_iterator 			c_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator 		r_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator 	c_r_iterator;

		iterator		begin();
		iterator		end();
		r_iterator		rbegin();
		r_iterator		rend();
		c_iterator		cbegin() const;
		c_iterator		cend() const;
		c_r_iterator	crbegin() const;
		c_r_iterator	crend() const;

};

#endif
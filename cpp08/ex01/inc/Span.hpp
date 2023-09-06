#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {

	public:

		Span();
		Span( unsigned int n );
		~Span();
		Span(Span & src);
		Span & operator=(Span & rhs);
		void	addNumber( int	add );
		int		shortestSpan( );
		int		longestSpan( );
		template< typename T >
		void	add_range( T iterator_start, T iterator_end );

		class StorageMaxException : public std::exception {

			public:
				const char *what() const throw()
				{
					return ("Can't add integers, vector is full\n");
				}
		};

		class NoSpanException : public std::exception {

			public:
				const char *what() const throw()
				{
					return ("No span exists, empty vector or just one number\n");
				}
		};

		std::vector<int>	int_vector;		//public so we can make copies and use the sort function in tests
};

#endif
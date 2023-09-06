#include "../inc/Span.hpp"

Span::Span() { }																							//DEFAULT CONSTRUCTOR
Span::~Span() { }																							//DESTRUCTOR
Span::Span( unsigned int n )																				//CONSTRUCTUR WITH UNSIGNED INT ARG
{
	try
	{
		this->int_vector.reserve(n);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}			
Span::Span(Span & src)																						//COPY CONSTRUCTOR
{
	try
	{
		this->int_vector.reserve(src.int_vector.capacity());
		*this = src;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

Span & Span::operator=(Span & src)																			//ASSIGNMENT OPERATOR OVERLOAD
{ 	
	if (this == &src || src.int_vector.empty() == true)
		return *this;
	for(std::vector<int>::iterator it = src.int_vector.begin(); it != src.int_vector.end(); ++it)
	{
		this->int_vector.push_back(*it);
	}
	return *this;
}
void	Span::addNumber( const int add )																	//ADDS A NUMBER TO THE VECTOR IF IT IS NOT AT MAXIMUM STORAGE CAPACITY
{
	if (this->int_vector.capacity() == this->int_vector.size())
		throw Span::StorageMaxException();
	this->int_vector.push_back(add);
	// std::cout << "added a number " << add << std::endl;
}

//sorts list small->big
//takes the diff between element 0 and 1 as the ret value
//then loops thorugh the vector and checks the diff between current element and next element
//if this diff is smaller then it sets ret as this new value
int		Span::shortestSpan()
{
	if (this->int_vector.empty() == true || this->int_vector.size() == 1)
		throw Span::NoSpanException();
	std::sort(this->int_vector.begin(), this->int_vector.end());
	int	ret = this->int_vector[1] - this->int_vector[0];
	for(std::vector<int>::iterator it = this->int_vector.begin(); it + 1 != this->int_vector.end(); ++it)
	{
		if (*(it + 1) - *it < ret)
		{
			ret = *(it + 1) - *it;
		}
	}
	return ret;
}

//simply uses max_element and min_element to find the longest span in the range
int		Span::longestSpan()
{
	if (this->int_vector.empty() == true || this->int_vector.size() == 1)
		throw Span::NoSpanException();
	return ((*std::max_element(this->int_vector.begin(), this->int_vector.end())) - (*std::min_element(this->int_vector.begin(), this->int_vector.end())));
}		

template< typename T >
void	Span::add_range( T iterator_start, T iterator_end )
{
	try
	{
		while (iterator_start != iterator_end)
		{
			addNumber(*iterator_start++);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

template void Span::add_range<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);

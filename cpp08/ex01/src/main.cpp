#include "../inc/Span.hpp"

#define RANGE INT_MAX

void	test_spans( Span *Span1)
{
	try
	{
		int longest = Span1->longestSpan();
		int shortest = Span1->shortestSpan();
		std::cout << "longest span: " << longest << std::endl;
		std::cout << "shortest span: " << shortest << std::endl;

		//testing longest span (in the call to shortestSpan, the vector has been sorted small->large)
		if (Span1->int_vector.back() - Span1->int_vector.front() != longest) //last element (largest) minus first element (smallest) is longest span!
			std::cout << "wrong span for longest span!" << std::endl;
		//testing shortest span
		std::vector<int>::iterator it = Span1->int_vector.begin();								
		for(std::vector<int>::iterator it2 = it + 1; it2 != Span1->int_vector.end(); ++it)		//looping through all elements of the vector from begin till end
		{
			if (*it2 - *it < shortest)														//checking if diff between element and next element is smaller then shortest
				std::cout << "wrong span for shortest span!" << std::endl;						
			it2++;
		}
		std::cout << "///\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	add_x_random( Span *Span, size_t x)
{
	int	add = 0;
	
	add = rand() % RANGE;
	try
	{
		for(size_t i = 0; i < x; ++i)
		{
			Span->addNumber(add);
			add = rand() % RANGE;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{	
	try
	{
		Span	*Span1 = new class Span(10);
		Span	*Span2 = new class Span(4);
		Span	*Span3 = new class Span(10000);
		std::vector<int> my_vector;
		srand(time(nullptr));

		add_x_random(Span1, 11);
		test_spans(Span1);

		my_vector.push_back(1000);
		my_vector.push_back(10);
		my_vector.push_back(1);
		Span2->add_range(my_vector.begin(), my_vector.end());
		test_spans(Span2);

		add_x_random(Span3, 10000);
		test_spans(Span3);

		delete Span1;
		delete Span2;
		delete Span3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

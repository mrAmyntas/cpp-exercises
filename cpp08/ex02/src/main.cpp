#include "../inc/MutantStack.tpp"


int main( void )
{
	{
		MutantStack<long> stack;

		stack.push(1);
		stack.push(2);
		stack.push(3);

		MutantStack<long>::iterator it;
		MutantStack<long>::c_iterator c_it;
		MutantStack<long>::r_iterator r_it;
		MutantStack<long>::c_r_iterator c_r_it;

		r_it = stack.rbegin();
		std::cout << *r_it << std::endl;

		r_it = stack.rend();
		std::cout << *(r_it - 1) << std::endl;
		
		c_it = stack.cbegin();
		std::cout << *c_it << std::endl;
		
		c_it = stack.cend();
		std::cout << *(c_it - 1) << std::endl;
		
		c_r_it = stack.crbegin();
		std::cout << *c_r_it << std::endl;

		c_r_it = stack.crend();
		std::cout << *(c_r_it - 1) << std::endl << std::endl;
	}
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;


		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::list<int>::iterator it2 = mlist.begin();
		std::list<int>::iterator ite2 = mlist.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		std::list<int> s2(mlist);
		std::cout << std::endl;

	}
	{
		MutantStack<int> mstack;
		mstack.push(12);
		mstack.push(19);
		mstack.push(21);

		MutantStack<int> copystack(mstack);
		std::cout << copystack.top() << std::endl;
		copystack.pop();
		std::cout << mstack.top() << std::endl;
		std::cout << copystack.top() << std::endl;
		copystack.push(13);
		copystack = mstack;
		std::cout << mstack.top() << " " << mstack.size() << std::endl;
		std::cout << copystack.top() << " " << copystack.size() << std::endl;
	}
	return 0;
}

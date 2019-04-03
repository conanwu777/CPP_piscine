#include "mutantstack.hpp"
# include <iostream>
# include <stack>
# include <iterator>

int main()
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
	while (it != ite) {
		std::cout << *it << std::endl;
		it++; }
	std::stack<int> s(mstack);

	std::cout << "Additional Tests\n";
	MutantStack<int> stack;
	std::cout << "empty: " << stack.empty() <<std::endl;
	for (int i = 0; i < 1000; i++)
		stack.push(std::rand() % 1000);
	std::cout << "empty: " <<stack.empty() <<std::endl;
	std::cout << "content:\n";
	for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
		std::cout << *it << " ";
	std::cout << "]\n";
	for (int i = 0; i < 500; i++)
		stack.pop();
	std::cout << "content:\n";
	for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
		std::cout << *it << " ";
	std::cout << "]\n";
	return 0;
}

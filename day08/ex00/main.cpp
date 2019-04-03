#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <map>

const char* NumberNotFoundException::what() const throw() {
	return ("Number Not Found");}

int main() {
	std::list<int> lst;

	for (int i = 0; i <= 42; i++)
		lst.push_back(i);
	try
	{
		std::cout << *easyfind(lst, 0) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *easyfind(lst, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *easyfind(lst, 43) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *easyfind(lst, 300) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
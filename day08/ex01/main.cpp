#include "span.hpp"
#include <iostream>

int main() {
	Span sp = Span(5);
	try
	{
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(5);
	sp2.addNumber(5);
	try
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Span sp3 = Span(50000);
	std::vector<int> vector;
	for (int i = 0; i < 50000; i++)
	{
		vector.push_back(std::rand() % 10000000);
	}
	sp3.addVector(vector);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
}

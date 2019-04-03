#include "Token.hpp"
#include "mutantstack.hpp"
#include <list>
#include <stack>
#include <string>
#include <iostream>

bool isOp(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return 1;
	return 0;
}

bool isDigit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int order(char c) {
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == ')')
		return 3;
	return 0;
}

std::list<Token> Tokenize(std::string str) {
	std::list<Token> list;

	int i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (isOp(str[i]) && !(str[i] == '-' && str[i + 1] && isDigit(str[i + 1])))
		{
			Token t(str[i]);
			list.push_back(t);
			i++;
		}
		else if (isDigit(str[i]) || (str[i] == '-' && str[i + 1] && isDigit(str[i + 1])))
		{
			Token t(atoi(&str[i]));
			list.push_back(t);
			i++;
			while (isDigit(str[i]))
				i++;
		}
		else
			i++;
	}
	std::cout << "Tokens: ";
	for (std::list<Token>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (it->getOp() == 1)
			std::cout << "Num[" << it->getN() << "]  ";
		else
			std::cout << "Op[" << it->getOp() << "]  ";
	}
	std::cout << std::endl;
	return list;
}

void doOp(MutantStack<Token>* Nums, MutantStack<Token>* Ops)
{
	int n1 = Nums->top().getN();
	Nums->pop();
	if (Nums->empty())
		throw InvalidExpressionException();
	int n2 = Nums->top().getN();
	Nums->pop();
	char op = Ops->top().getOp();
	if (Ops->empty())
		throw InvalidExpressionException();
	Ops->pop();
	int n;
	if (op == '+')
		n = n2 + n1;
	else if (op == '-')
		n = n2 - n1;
	else if (op == '*')
		n = n2 * n1;
	else
		n = n2 / n1;
	Token t(n);
	Nums->push(t);
}

void listToStacks(std::list<Token> list, MutantStack<Token>* Nums, MutantStack<Token>* Ops)
{
	for (std::list<Token>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << "Token: ";
		if (it->getOp() == 1)
			std::cout << "Num[" << it->getN() << "]" << std::endl;
		else
			std::cout << "Op[" << it->getOp() << "]" << std::endl;
		if (it->getOp() == 1)
			Nums->push(*it);
		else if (order(it->getOp()) == 1 &&
			!Ops->empty() && order(Ops->top().getOp()) == 2)
		{
			doOp(Nums, Ops);
			Nums->push(*it);
		}
		else if (it->getOp() == ')')
		{
			while (Ops->top().getOp() != '(')
				doOp(Nums, Ops);
			Ops->pop();
		}
		else
			Ops->push(*it);

		std::cout << "    Ops Stack: ";
		MutantStack<Token>::iterator it1 = Ops->begin();
		while (it1 != Ops->end())
		{
			std::cout << it1->getOp() << " ";
			it1++;
		}
		std::cout << "]\n";

		std::cout << "    Numbers Stack: ";
		MutantStack<Token>::iterator it2 = Nums->begin();
		while (it2 != Nums->end())
		{
			std::cout << it2->getN() << " ";
			it2++;
		}
		std::cout << "]\n";
	}
}

int main (int ac, char** av)
{
	std::list<Token> list;
	MutantStack<Token> Nums;
	MutantStack<Token> Ops;

	if (ac != 2 || av[1][0] == '\0')
		return -1;
	std::string str = av[1];
	list = Tokenize(str);
	if (list.empty())
		return -1;
	listToStacks(list, &Nums, &Ops);
	try 
	{
		while (!Ops.empty())
		{
			std::cout << "Token: Op[" << Ops.top().getOp() << "]\n";
			doOp(&Nums, &Ops);
			std::cout << "    Ops Stack: ";
			MutantStack<Token>::iterator it1 = Ops.begin();
			while (it1 != Ops.end())
			{
				std::cout << it1->getOp() << " ";
				it1++;
			}
			std::cout << "]\n";

			std::cout << "    Numbers Stack: ";
			MutantStack<Token>::iterator it2 = Nums.begin();
			while (it2 != Nums.end())
			{
				std::cout << it2->getN() << " ";
				it2++;
			}
			std::cout << "]\n";
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
	std::cout << "Result: " << Nums.top().getN() << std::endl;
	return 0;
}

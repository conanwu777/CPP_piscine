#include <iostream>
#include <string>
#include <float.h>
#include <iomanip>
#include <math.h>
#include <stdexcept>

int char_conv(char c) {
	if (!isprint(c))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << c << std::endl;
	int i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;
	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << std::endl;
	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;
	return 0;
}

int double_conv(double d) {
	if (d < 0 || d > 255)
		std::cout << "char: impossble\n";
	else
	{
		char c = static_cast<char>(d);
		if (!isprint(c))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: " << c << std::endl;
	}
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossble\n";
	else
	{
		int i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout << "float: impossble\n";
	else {
		float f = static_cast<float>(d);
		if (f == static_cast<float>(static_cast<int>(d)))
			std::cout << std::setprecision(1) << std::fixed;
		else
			std::cout << std::setprecision(9);
		std::cout << "float: " << f << "f" << std::endl;
	}
	if (static_cast<float>(d) == static_cast<float>(static_cast<int>(d)))
		std::cout << std::setprecision(1) << std::fixed;
	else
	std::cout << std::setprecision(15);
	std::cout << "double: " << d << std::endl;
	return 0;
}

int special_conv(std::string str) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (!str.compare("nan") || !str.compare("nanf"))
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (!str.compare("+inf") || !str.compare("+inff") ||
		!str.compare("inf") || !str.compare("inff"))
	{
		std::cout << "float: inff\n";
		std::cout << "double: inf\n";
	}
	else
	{
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
	return 0;
}

int main(int ac, char** av)
{
	unsigned int c = 0;
	unsigned int i;
	bool f;
	double d;

	if (ac != 2)
		return 0;
	std::string str = static_cast<std::string>(av[1]);
	if (!str.compare("+inf") || !str.compare("+inff") ||
		!str.compare("inf") || !str.compare("inff") ||
		!str.compare("-inf") || !str.compare("-inff") ||
		!str.compare("nan") || !str.compare("nanf"))
		return special_conv(str);
	if (str.size() == 1 && (str[0] < '0' || str[0] > '9'))
	{
		char c = str[0];
		return char_conv(c);
	}
	f = 0;
	if (str[str.size() - 1] == 'f')
	{
		str = str.substr(0, str.size() - 1);
		f = 1;
	}
	for (i = 0; i < str.size(); i++)
		if (str[i] == '.')
			c++;
	if (c > 1)
		return 0;
	c = 0;
	if (str[c] == '-' && str.size() > 1)
		c++;
	for (i = c; i < str.size(); i++)
		if (!isdigit(str[i]) && str[i] != '.')
			break ;
	if (i == str.size())
	{
		try {
			d = stod(str);
		}
		catch (std::exception &e)
		{
			d = INFINITY;
		}
		if (f == 1 && (d < FLT_MIN || d > FLT_MAX))
			d = INFINITY;
		return double_conv(d);
	}
	return 0;
}
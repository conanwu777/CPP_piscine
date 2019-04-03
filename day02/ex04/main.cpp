#include "Fixed.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

std::string get_float(float *f, std::string str)
{
	int i = 1;

	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
	{
		str.clear();
		return (str);
	}
	while (str[i] && str[i] != ' ')
		i++;
	if (!str[i])
	{
		*f = stof(str);
		str.clear();
		return (str);
	}
	*f = stof(str.substr(0, i));
	return (str.substr(i + 1, str.size() - i - 1));
}

std::string get_float_rev(std::string str, float *f)
{
	int i = str.size() - 1;

	while (str[i] && str[i] == ' ')
		i--;
	if (i < 0)
	{
		str.clear();
		return (str);
	}
	while (i >= 0 && str[i] != ' ')
		i--;
	*f = stof(str.substr(i + 1, str.size()));
	if (i < 0)
	{
		str.clear();
		return (str);
	}
	return (str.substr(0, i + 1));
}

int match(std::string str, int n)
{
	int i = n + 1;
	int d = 0;

	while (str[i])
	{
		if (str[i] == '(')
			d++;
		else if (str[i] == ')' && d > 0)
			d--;
		else if (str[i] == ')' && d == 0)
			return (i);
		i++;
	}
	return (-1);
}

Fixed do_op(Fixed F1, char c, Fixed F2)
{
	if (c == '*')
		return (F1 * F2);
	if (c == '/')
		return (F1 / F2);
	if (c == '+')
		return (F1 + F2);
	else
		return (F1 - F2);
}

Fixed eval(std::string str)
{	
	std::size_t n;
	int n2;
	std::string t;
	std::string t2;
	std::string t3;
	float f1;
	float f2;
	char c;

	if ((n = str.find("(")) != std::string::npos)
	{
		if (!(n2 = match(str, n)))
			return (-1);
		t = str.substr(n + 1, n2 - n - 1);
		Fixed res = eval(t);
		t2 = str.substr(0, n);
		t3 = str.substr(n2 + 1, str.size() - n2 - 1);
		std::ostringstream ofs;
		ofs << t2 << " " << res << " " << t3;
		str = ofs.str();
	}
	else
	{
		if ((n = str.find("*")) != std::string::npos)
			c = '*';
		else if ((n = str.find("/")) != std::string::npos)
			c = '/';
		else if ((n = str.find("+")) != std::string::npos)
			c = '+';
		else if ((n = str.find("- ")) != std::string::npos)
			c = '-';
		else
			return (Fixed(stof(str)));
		t = str.substr(0, n - 1);
		t = get_float_rev(t, &f1);
		t2 = str.substr(n + 1, str.size() - n - 1);
		if (c == '/' && stof(t2) == 0)
		{
			std::cout << "Division by ";
			return (0);
		}
		t2 = get_float(&f2, t2);
		Fixed F1(f1);
		Fixed F2(f2);
		Fixed F = do_op(F1, c, F2);
		std::ostringstream ofs;
		ofs << t << " " << F << " " << t2;
		str = ofs.str();
	}
	return (eval(str));
}

int main(int ac, char **av) {
	if (ac != 2)
		return 0;
	std::string str(av[1]);
	std::cout << eval(str) << std::endl;
	return 0;
}

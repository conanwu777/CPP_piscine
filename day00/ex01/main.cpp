#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void add_contact(Contact lst[8])
{
	int i = -1;
	std::string empty("");
	std::string buf;

	while (++i < 8)
		if (empty.compare(lst[i].getFn()) == 0)
		{
			std::getline (std::cin, empty);
			std::cout << "First name: ";
			std::getline (std::cin, buf);
			lst[i].setFn(buf);
			std::cout << "Last name: ";
			std::getline (std::cin, buf);
			lst[i].setLn(buf);
			std::cout << "Nick name: ";
			std::getline (std::cin, buf);
			lst[i].setNn(buf);			
			std::cout << "Login: ";
			std::getline (std::cin, buf);
			lst[i].setLogin(buf);
			std::cout << "Postal address: ";
			std::getline (std::cin, buf);
			lst[i].setPa(buf);
			std::cout << "Email address: ";
			std::getline (std::cin, buf);
			lst[i].setEmail(buf);
			std::cout << "Phone number: ";
			std::getline (std::cin, buf);
			lst[i].setNum(buf);
			std::cout << "Birth date: ";
			std::getline (std::cin, buf);
			lst[i].setBd(buf);
			std::cout << "Favouriate meal: ";
			std::getline (std::cin, buf);
			lst[i].setMeal(buf);
			std::cout << "Underwear color: ";
			std::getline (std::cin, buf);
			lst[i].setUw(buf);
			std::cout << "Darkest secret: ";
			std::getline (std::cin, buf);
			lst[i].setSec(buf);
			break ;
		}
	if (empty.compare(lst[7].getFn()) != 0)
		std::cout << "Your phone book is FULL" << std::endl;
}

std::string copy10(std::string buf)
{
	std::string cpy;

	cpy = buf;
	cpy = cpy.substr(0, 11);
	if (cpy.length() >= 11)
	{
		cpy[9] = '.';
		cpy[10] = '\0';
	}
	return (cpy);
}

void search_contact(Contact lst[8])
{
	int i = -1;
	std::string empty("");
	std::string cpy;

	while (++i < 8 && empty.compare(lst[i].getFn()) != 0)
	{
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << i + 1 << "|";
		cpy = copy10(lst[i].getFn());
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << cpy << "|";
		cpy = copy10(lst[i].getLn());
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << cpy << "|";
		cpy = copy10(lst[i].getNn());
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << cpy << std::endl;
	}
	std::cout << "Index: ";
	while (true)
	{
		std::cin >> cpy;
		if (cpy.length() == 1)
		{
			i = cpy[0] - '1';
			if (i >= 0 && i <= 7 && empty.compare(lst[i].getFn()) != 0)
				break ;
		}
		std::cout << "Invalid index" << std::endl;
	}
	std::cout << "First name: " << lst[i].getFn() << std::endl;
	std::cout << "Last name: " << lst[i].getLn() << std::endl;
	std::cout << "Nick name: " << lst[i].getNn() << std::endl;
	std::cout << "Login: " << lst[i].getLogin() << std::endl;
	std::cout << "Postal address: " << lst[i].getPa() << std::endl;
	std::cout << "Email address: " << lst[i].getEmail() << std::endl;
	std::cout << "Phone number: " << lst[i].getNum() << std::endl;
	std::cout << "Birth date: " << lst[i].getBd() << std::endl;
	std::cout << "Favouriate meal: " << lst[i].getMeal() << std::endl;
	std::cout << "Underwear color: " << lst[i].getUw() << std::endl;
	std::cout << "Darkest secret: " << lst[i].getSec() << std::endl;
}

int ops(std::string buf, Contact lst[8])
{
	std::string add ("ADD");
	std::string search ("SEARCH");
	std::string exit ("EXIT");

	if (add.compare(buf) && search.compare(buf) && exit.compare(buf))
		return -1;
	else if (!add.compare(buf))
		add_contact(lst);
	else if (!search.compare(buf))
		search_contact(lst);
	else
		return 0;
	return 1;
}

int main()
{
	Contact lst[8];
	std::string buf;
	int op = 1;

	while (op == 1 && std::cin.good())
	{
		std::cout << "What would you like to do now?" << std::endl;
		std::cin >> buf;
		op = ops(buf, lst);
		if (op == -1)
		{
			std::cout << "Accepted instructions are ADD, SEARCH and EXIT" << std::endl;
			op = 1;
		}
	}
	return 0;
}

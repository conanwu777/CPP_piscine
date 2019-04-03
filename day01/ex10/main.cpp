#include <iostream>
#include <fstream>

int main(int ac, char **av) {
	std::string str;
	std::string empty = "";

	if (ac == 1)
		while (getline(std::cin, str))
			std::cout << str << std::endl;
	for (int i = 1; i < ac; i++)
	{
		std::ifstream ifs(av[i]);
		if (!ifs.good())
		{
			std::cout << "cat: "<< av[i] << ": No such file or directory\n";
			continue ;
		}
		while (!ifs.eof())
		{
			getline(ifs, str);
			std::cout << str;
			if (!ifs.eof())
				std::cout << std::endl;
		}
		ifs.close();
	}
	return 0;
}

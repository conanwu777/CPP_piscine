#include <iostream>

int main(int ac, char **av)
{
	int count = 1;
	int i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (count < ac)
	{
		i = -1;
		while (av[count][++i])
			if ('a' <= av[count][i] && av[count][i] <= 'z')
				av[count][i] += 'A' - 'a';
		std::cout << av[count];
		count++;
	}
	std::cout << std::endl;
	return 0;
}

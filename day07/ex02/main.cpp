#include "Array.tpp"

int main ()
{
	Array<int> tab(10);
	Array<int> cpy;

	for (unsigned int i = 0; i < tab.size(); i++)
	{
		tab[i] = 42 + i;
		std::cout << tab[i] << " ";
	}
	std::cout << std::endl;
	cpy = tab;
	for (unsigned int i = 0; i < cpy.size(); i++)
		std::cout << cpy[i] << " ";
	std::cout << std::endl;
	Array<int> cpy2 = Array<int>(tab);
	for (unsigned int i = 0; i < cpy2.size(); i++)
		std::cout << cpy2[i] << " ";
	std::cout << std::endl;
	return 0;
}

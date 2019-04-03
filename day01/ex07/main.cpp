#include <fstream>
#include <iostream>
#include <string>

std::string to_upper(char *str)
{
	std::string res;
	int i = -1;

	while (str[++i])
		if ('a' <= str[i] && str[i] <= 'z')
			res += (str[i] + 'A' - 'a');
		else
			res += str[i];
	return (res);
}

int main(int ac, char **av)
{
	std::string name;
	std::string content;
	std::string tmp;
	std::string s1;
	char c;

	if (ac != 4 || av[2][0] == '\0' || av[3][0] == '\0' || !(std::ifstream(av[1])))
	{
		std::cout << "Invalid input" << std::endl;
		return (-1);
	}
	std::ifstream ifs(av[1]);
	while (ifs.get(c))
		content += c;
	ifs.close();
	s1 += av[2];
	tmp += 1;
	while (content.find(s1) != std::string::npos)
		content.replace(content.find(s1), s1.length(), tmp);
	while (content.find(tmp) != std::string::npos)
		content.replace(content.find(tmp), tmp.length(), av[3]);
	name = to_upper(av[1]);
	name += ".replace";
	std::ofstream ofs(name);
	ofs << content;
	ofs.close();
	return 0;
}

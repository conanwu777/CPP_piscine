#include "Instructions.hpp"
#include <fstream>

Instruction* addPi() {
	return new pi();}

Instruction* addPd() {
	return new pd();}

Instruction* addI() {
	return new i();}

Instruction* addD() {
	return new d();}

Instruction* addO() {
	return new o();}

Instruction* addR() {
	return new r();}

Instruction* addWst() {
	return new wst();}

Instruction* addWed() {
	return new wed();}

void mindopen(std::string file)
{
	std::map<char, Instruction* (*)(void)> map;
	map['r'] = addPi;
	map['l'] = addPd;
	map['p'] = addI;
	map['m'] = addD;
	map['o'] = addO;
	map['i'] = addR;
	map['b'] = addWst;
	map['e'] = addWed;

	std::list<Instruction*> list;
	std::fstream ifs(file);
	char c;
	while (ifs.get(c))
		if (map.count(c))
			list.push_back(map[c]());

	std::string str;
	int pos;
	std::list<Instruction*>::iterator it;
	it = list.begin();
	while (it != list.end())
	{
		(*it)->excute(&str, &pos, &it);
		it++;
	}
	ifs.close();
}

int main(int ac, char** av)
{
	if (ac == 2)
	{
		mindopen(av[1]);
		std::cout << std::endl;
	}
	return 0;
}
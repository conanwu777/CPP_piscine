#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>
#include <ctime>

struct Data {
	std::string s1;
	int 		n;
	std::string s2;
};

static char randcharacter(int r) {
	r = r % 62;
	if (r < 10)
		return ('0' + r);
	else if (r < 36)
		return ('a' + r - 10);
	else
		return ('A' + r - 36);
}

void* serialize( void ) {
	static int st = 0;
	char buf[21];

	if (st == 0)
		srand(time(NULL));
	st = 1;
	for (int j = 0; j < 8; j++)
		buf[j] = randcharacter(rand());
	int i = rand() % INT_MAX;
	char *cptr = reinterpret_cast<char*>(&i);
	for (int j = 0; j < 4; j++)
		buf[8 + j] = cptr[j];
	for (int j = 0; j < 8; j++)
		buf[12 + j] = randcharacter(rand());
	std::string str = std::string(buf);
	return static_cast<void*>(&str[0]);
}

Data* deserialize(void * raw) {
	Data * d = new Data();
	char *cptr;

	cptr = static_cast<char*>(raw);
	d->n = *(reinterpret_cast<int*>(&cptr[8]));
	std::string str = std::string(cptr);
	d->s1 += str.substr(0, 8);
	std::string str2 = std::string(&cptr[12]);
	d->s2 += str2.substr(0, 8);
	return d;
}

int main(){
	Data* d;
	
	d = deserialize(serialize());
	std::cout << d->s1 << std::endl;
	std::cout << d->n << std::endl;
	std::cout << d->s2 << "\n";
	delete d;
	return 0;
}
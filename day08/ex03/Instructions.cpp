#include "Instructions.hpp"

pi::pi(const pi &) {}
pi & pi::operator=(const pi &) {
	return *this;}
pi::pi() {}
pi::~pi() {}
void pi::excute(std::string *, int *pos,
	std::list<Instruction*>::iterator *) {
	*pos += 1;
}

pd::pd(const pd &) {}
pd & pd::operator=(const pd &) {
	return *this;}
pd::pd() {}
pd::~pd() {}
void pd::excute(std::string *, int *pos,
	std::list<Instruction*>::iterator *) {
	*pos -= 1;
}

i::i(const i &) {}
i & i::operator=(const i &) {
	return *this;}
i::i() {}
i::~i() {}
void i::excute(std::string *str, int *pos,
	std::list<Instruction*>::iterator *) {
	(*str)[*pos]++;
}

d::d(const d &) {}
d & d::operator=(const d &) {
	return *this;}
d::d() {}
d::~d() {}
void d::excute(std::string *str, int *pos,
	std::list<Instruction*>::iterator *) {
	(*str)[*pos]--;
}

o::o(const o &) {}
o & o::operator=(const o &) {
	return *this;}
o::o() {}
o::~o() {}
void o::excute(std::string *str, int *pos,
	std::list<Instruction*>::iterator *) {
	std::cout << (*str)[*pos];
}

r::r(const r &) {}
r & r::operator=(const r &) {
	return *this;}
r::r() {}
r::~r() {}
void r::excute(std::string *str, int *pos,
	std::list<Instruction*>::iterator *) {
	(*str)[*pos] = std::cin.get();
}

wst::wst(const wst &) {}
wst & wst::operator=(const wst &) {
	return *this;}
wst::wst() {}
wst::~wst() {}
void wst::excute(std::string *str, int *pos,
	std::list<Instruction*>::iterator *it) {
	if (!(*str)[*pos])
	{
		int d = 0;
		while (1)
		{
			(*it)++;
			if (dynamic_cast<wed*>(**it) && d == 0)
				break ;
			else if (dynamic_cast<wed*>(**it))
				d--;
			else if (dynamic_cast<wst*>(**it))
				d++;
		}
	}
}

wed::wed(const wed &) {}
wed & wed::operator=(const wed &) {
	return *this;}
wed::wed() {}
wed::~wed() {}
void wed::excute(std::string *str, int *pos,
	std::list<Instruction*>::iterator *it) {
	if ((*str)[*pos])
	{
		int d = 0;
		while (1)
		{
			(*it)--;
			if (dynamic_cast<wst*>(**it) && d == 0)
				break ;
			else if (dynamic_cast<wst*>(**it))
				d--;
			else if (dynamic_cast<wed*>(**it))
				d++;
		}
	}
}

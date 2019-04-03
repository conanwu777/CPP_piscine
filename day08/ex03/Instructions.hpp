#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP
# include <iostream>
# include <map>
# include <list>

class Instruction {
	public:
		virtual void excute(std::string *str, int *pos,
			std::list<Instruction*>::iterator *it) = 0;
};

class pi : public Instruction {
public:
	pi(const pi & src);
	pi & operator=(const pi & rhs);
	pi();
	~pi();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

class pd : public Instruction {
public:
	pd(const pd & src);
	pd & operator=(const pd & rhs);
	pd();
	~pd();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

class i : public Instruction {
public:
	i(const i & src);
	i & operator=(const i & rhs);
	i();
	~i();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

class d : public Instruction {
public:
	d(const d & src);
	d & operator=(const d & rhs);
	d();
	~d();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

class o : public Instruction {
public:
	o(const o & src);
	o & operator=(const o & rhs);
	o();
	~o();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

class r : public Instruction {
public:
	r(const r & src);
	r & operator=(const r & rhs);
	r();
	~r();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

class wst : public Instruction {
public:
	wst(const wst & src);
	wst & operator=(const wst & rhs);
	wst();
	~wst();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

class wed : public Instruction {
public:
	wed(const wed & src);
	wed & operator=(const wed & rhs);
	wed();
	~wed();
	void excute(std::string *str, int *pos,
		std::list<Instruction*>::iterator *it);
};

#endif

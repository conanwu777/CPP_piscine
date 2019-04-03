#ifndef BASE_HPP
# define BASE_HPP

class Base {
		Base(const Base & src);
		Base & operator=(const Base & rhs);
	public:
		Base();
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif

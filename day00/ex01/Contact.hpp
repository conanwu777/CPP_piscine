#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
	std::string fn;
	std::string ln;
	std::string nn;
	std::string login;
	std::string pa;
	std::string email;
	std::string num;
	std::string bd;
	std::string meal;
	std::string uw;
	std::string sec;
	
public:
	Contact(void);
	~Contact(void);

	std::string getFn(void) const;
	std::string getLn(void) const;
	std::string getNn(void) const;
	std::string getLogin(void) const;
	std::string getPa(void) const;
	std::string getEmail(void) const;
	std::string getNum(void) const;
	std::string getBd(void) const;
	std::string getMeal(void) const;
	std::string getUw(void) const;
	std::string getSec(void) const;

	void setFn(std::string);
	void setLn(std::string);
	void setNn(std::string);
	void setLogin(std::string);
	void setPa(std::string);
	void setEmail(std::string);
	void setNum(std::string);
	void setBd(std::string);
	void setMeal(std::string);
	void setUw(std::string);
	void setSec(std::string);
};

#endif

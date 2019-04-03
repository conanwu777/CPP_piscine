#include "Token.hpp"

Token::Token(int k) : n(k), op(1) {}

Token::Token(char c) : n(-17), op(c) {}

Token::Token(const Token & src) {*this = src; }

Token::~Token() {}

int Token::getN() const {return(n);}

char Token::getOp() const {return(op);}

Token & Token::operator=(const Token & rhs) {
	this->n = rhs.getN();
	this->op = rhs.getOp();
	return *this;
}

const char* InvalidExpressionException::what() const throw() {
	return ("Invalid Expression");}
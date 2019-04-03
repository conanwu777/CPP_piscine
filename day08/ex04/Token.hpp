#ifndef TOKEN_HPP
# define TOKEN_HPP
# include <stdexcept>

class Token {
		int n;
		char op;
		Token();
	public:
		Token(const Token &);
		~Token();
		Token & operator=(const Token &);
		Token(int);
		Token(char);
		int getN() const;
		char getOp() const;
};

class InvalidExpressionException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif

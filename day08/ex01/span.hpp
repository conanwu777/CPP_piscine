#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

class Span {
	std::vector<int> v;
	int count;
	Span();
public:
	Span(unsigned int N);
	Span(Span const & src);
	~Span();
	std::vector<int> getVector() const;
	int getCount() const;
	Span & operator=(Span const & rhs);
	void addNumber(int n);
	void addVector(std::vector<int> vector);
	int shortestSpan();
	int longestSpan();

	class NotEnoughSpaceException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class TooFewElemException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
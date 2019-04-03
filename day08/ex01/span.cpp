#include "span.hpp"
#include <algorithm>

Span::Span(unsigned int N) {
	v = std::vector<int>();
	count = N;
}

Span::Span(Span const & src) {
	*this = src;
}

Span::~Span(){}

Span & Span::operator=(Span const & rhs) {
	this->v = rhs.getVector();
	this->count = rhs.getCount();
	return *this;
}

std::vector<int> Span::getVector() const {
	return this->v;
}

int Span::getCount() const {
	return this->count;
}

void Span::addNumber(int n) {
	if (this->count > 0)
		this->v.push_back(n);
	else
		throw NotEnoughSpaceException();
	this->count--;
}

void Span::addVector(std::vector<int> vector) {
	if (this->count - static_cast<int>(vector.size()) >= 0)
		v.insert(v.end(), vector.begin(), vector.end());
	else
		throw NotEnoughSpaceException();
}

int Span::shortestSpan() {
	if (v.size() <= 1)
		throw TooFewElemException();
	sort(v.begin(), v.end());
	int min = v.at(1) - v.at(0);
	for (std::vector<int>::iterator iter = v.begin() + 1; iter < v.end() - 1; iter++)
		if (*(iter + 1) - *iter < min)
			min = *(iter + 1) - *iter;
	return min;
}

int Span::longestSpan() {
	if (v.size() <= 1)
		throw TooFewElemException();
	sort(v.begin(), v.end());
	int max = v.at(v.size() - 1) - v.at(0);
	return max;
}

const char* Span::NotEnoughSpaceException::what() const throw() {
	return ("Not Enough Space in the Span");}

const char* Span::TooFewElemException::what() const throw() {
	return ("Not enough elements");}
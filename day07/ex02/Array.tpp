#ifndef ARRAY_TPP
# define ARRAY_TPP
# include <iostream>
# include <stdexcept>

template<typename T>
class Array {
		T* arr;
		unsigned int sz;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array & src);
		~Array();

		Array & operator=(const Array & rhs);
		T & operator[](const int i) const;
		unsigned int size() const;

		class outOfLimitsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

template<typename T>
Array<T>::Array() : arr(NULL), sz(0) {}

template<typename T>
Array<T>::Array(unsigned int n) {
	arr = new T[n];
	sz = n;
}

template<typename T>
Array<T>::Array(const Array<T> & src) {
	*this = src;
}

template<typename T>
Array<T>::~Array() {}

template<typename T>
Array<T> & Array<T>::operator=(const Array<T> & rhs) {
	arr = new T[rhs.size()];
	for (unsigned int i = 0; i < rhs.size(); i++)
		arr[i] = rhs[i];
	this->sz = rhs.size();
	return *this;
}

template<typename T>
T & Array<T>::operator[](const int i) const {
	return arr[i];
}

template<typename T>
unsigned int Array<T>::size() const {
	return sz;
}

template<typename T>
const char* Array<T>::outOfLimitsException::what() const throw() {
		return ("Index given is out of limits");}

#endif
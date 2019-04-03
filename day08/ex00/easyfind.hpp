#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

class NumberNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

template<typename T>
typename T::iterator easyfind(T t, int n) {
	typename T::iterator iter = find(t.begin(), t.end(), n);
	if (iter == t.end())
		throw NumberNotFoundException();
	return iter;
}

#endif

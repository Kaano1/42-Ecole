#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::begin;
using std::end;
using std::exception;


template <typename T>
typename T::iterator easyfind(T container, int n)
{
	typename T::iterator itr;

	itr = find(begin(container), end(container), n);
	if (itr == end(container))
		throw std::exception();
	return itr;
}

#endif
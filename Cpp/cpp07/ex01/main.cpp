#include <iostream>
#include "iter.hpp"

template<class T>
void iter(T *arr, int size, void (*f)(T const&))
{
	for(int i = 0; i < size; i++)
		f(arr[i]);
}


template<class T>
void iter(T *arr, int size, void (*f)(T &))
{
	for(int i = 0; i < size; i++)
		f(arr[i]);
}

template< typename T >
void print( T const & x )
{
	std::cout << x << std::endl; return;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};

	iter(tab, 5, print);
	return 0;
}
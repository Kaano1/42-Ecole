#ifndef A_HPP
# define A_HPP

#include "Base.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::exception;
using std::cerr;

class A: public Base
{
	public:
		A();
		~A();
};

#endif
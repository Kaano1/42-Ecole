#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::exception;
using std::sort;
using std::begin;
using std::end;
using std::cerr;

class Span
{
	private:
		std::vector<int> list;
		unsigned int len;
	public:
		Span();
		Span(const Span& oth);
		Span(unsigned int n);
		Span& operator = (const Span& oth);
		~Span();

		void addNumber(int nb);
		int shortestSpan(void);
		int longestSpan(void);

		struct Error : public exception
		{
			const char * what() const throw();
		};

};

#endif
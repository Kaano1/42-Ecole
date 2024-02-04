#include "Span.hpp"

Span::Span()
{
	len = 0;
};

Span::Span(unsigned int n)
{
	list.reserve(n);
	len = n;
};

Span::Span(const Span &oth)
{
	*this = oth;
};

Span& Span::operator=(const Span &oth)
{
	this->list = oth.list;
	this->len = oth.len;

	return *this;
}

Span::~Span() {  };

const char * Span::Error::what() const throw()
{
	return "Error!";
}


void Span::addNumber(int nb)
{
	if ( list.size() >= len )
		throw Error();
	list.push_back(nb);
}

int Span::shortestSpan(void)
{
	if ( list.size() <= 1 )
		throw Error();
	sort( list.begin(), list.end() );
	int min = list[1] - list[0];
	for ( unsigned int i = 1; i < list.size(); ++i )
	{
		if ( list[i] - list[i - 1] < min )
			min = list[i] - list[i - 1];
	}
	return min;
}

int Span::longestSpan(void)
{
	if ( list.size() <= 1 )
		throw Error();
	sort( list.begin(), list.end() );
	int max = list[1] - list[0];
	for ( unsigned int i = 1; i < list.size(); ++i )
	{
		if ( list[i] - list[i - 1] < max )
			max = list[i] - list[i - 1];
	}
	return max;
}

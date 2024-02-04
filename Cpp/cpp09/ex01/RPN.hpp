#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <stack>

class RPN
{
    private:
        std::string				argument;
		std::deque<std::string>	elements;
    public:
		RPN();
		RPN(const 	RPN& copy);
		RPN &operator=(RPN const &rhs);
		~RPN();
        RPN(std::string& str);
		void	split();
		void	check();
		void	calculate();
		class ErrorException : public std::exception {
			private:
				const char *exceptionStr;
			public:
				ErrorException(const char *inputStr) : exceptionStr(inputStr) {};
				const char *what() const throw(){
					return (exceptionStr);
				}
		};
};

bool	isNumber(std::string str);
bool	isOperator(std::string str);

#endif
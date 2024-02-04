#include "RPN.hpp"

RPN::RPN(void)
{
    std::cout << "Default Constructor Call" << std::endl;
}

RPN::RPN(std::string& str)
{
	this->argument = str;
}

RPN::RPN(const 	RPN& copy)
{
	this->argument = copy.argument;
}

RPN &RPN::operator=(RPN const &rhs)
{
    std::cout << "Operator Overload Call" << std::endl;
	this->argument = rhs.argument;
	return (*this);
}

RPN::~RPN(void){
}

bool	isNumber(std::string str)
{
	int	convertedInt;
	try
	{
		convertedInt = std::stoi(str);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
	return (true);
}

bool	isOperator(std::string str)
{
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return (true);
	else
		return (false);
}

void	RPN::check(void)
{
	std::deque<std::string>::iterator	it;
	int numberCount = 0;
	int operatorCount = 0;

	it = this->elements.begin();
	for(; it != this->elements.end(); it++)
	{
		if ((*it).size() != 1)
			throw RPN::ErrorException("Error: expression cannot contain anything except for an operator or number.");
		if (isNumber(*it))
			numberCount++;
		if (isOperator(*it))
			operatorCount++;
		if (it == this->elements.begin() && isNumber(*it) == false)
			throw RPN::ErrorException("Error: expression cannot start without number.");
		if ((it + 1) == this->elements.end() && isOperator(*it) == false)
			throw RPN::ErrorException("Error: expression cannot end without operator.");
		if (isNumber(*it) == false && isOperator(*it) == false)
			throw RPN::ErrorException("Error: expression cannot contain anything except for an operator or number.");
	}
	if (operatorCount != (numberCount - 1))
		throw RPN::ErrorException("Error: invalid input.");
}

std::string doInst(int first, int second, std::string oprtr)
{
	std::string returnStr;
	if (oprtr == "+")
		returnStr = std::to_string(first + second);
	if (oprtr == "-")
		returnStr = std::to_string(first - second);
	if (oprtr == "*")
		returnStr = std::to_string(first * second);
	if (oprtr == "/"){
		if (second == 0)
			throw RPN::ErrorException("Error: you cannot divide by 0");
		returnStr = std::to_string(first / second);
	}
	return (returnStr);
}

void	RPN::calculate(void)
{
	std::stack<std::string> stack;
	std::deque<std::string>::iterator beginItr;
	std::deque<std::string>::iterator endItr;
	
	beginItr = this->elements.begin();
	endItr = this->elements.end();
	while (beginItr != endItr && isNumber(*beginItr) == true)
	{
		if (stack.size() == 0 && this->elements.size() == 1)
			break ;
		if (isNumber(this->elements.front()) == true)
		{
			while (beginItr != endItr && isOperator(this->elements.front()) == false)
			{
				stack.push(this->elements.front());
				this->elements.pop_front();
				beginItr = this->elements.begin();
			}
			if (stack.size() < 2 || this->elements.size() <= 0)
				throw ErrorException("Error: invalid arguments.");
			while (beginItr != endItr && isNumber(this->elements.front()) == false && stack.size() >= 2)
			{
				int second = std::stoi(stack.top());
				stack.pop();
				int first = std::stoi(stack.top());
				stack.pop();
				std::string oprtr = this->elements.front();
				this->elements.pop_front();
				stack.push(doInst(first, second, oprtr));
				beginItr = this->elements.begin();
			}
			while (stack.size() != 0)
			{
				this->elements.push_front(stack.top());
				stack.pop();
			}
		}
	}
	std::cout << this->elements.front() << std::endl;
}

void	RPN::split(void)
{
	std::string tmp;
	std::istringstream isS(this->argument);

	while (isS >> tmp)
		this->elements.push_back(tmp);
}

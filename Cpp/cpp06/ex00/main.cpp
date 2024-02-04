#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Invalid argument!" << endl;
		return (0);
	}
	
	try
	{
		string str(av[1]);
		if (!ScalarConverter::convert(str))
			throw std::runtime_error("Invalid Input");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

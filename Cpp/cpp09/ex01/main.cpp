#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
		std::string str(av[1]);
		RPN		rpn(str);
		try
		{
			rpn.split();
			rpn.check();
			rpn.calculate();
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
    }
    else
        std::cout << "Error: invalid input." << std::endl;
    return 0;
}
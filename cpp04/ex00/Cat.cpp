#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	cout << "Cat Worked" << endl;
}

Cat::~Cat()
{
	cout << "Cat Destroyed" << endl;
}

void	Cat::operator=(const Cat& oth)
{
	type = oth.type;
	cout << "Cat copy assigment operator called" << endl;
}

void Cat::makeSound() const
{
	cout << "The Cat sound" << endl;
}

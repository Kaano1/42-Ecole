#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	cout << "Cat Worked" << endl;
	beg = new Brain();
}

Cat::Cat(const Cat& oth)
{
	*this = oth;
}

Cat::~Cat()
{
	cout << "Cat Destroyed" << endl;
	delete beg;
}

Cat	&Cat::operator=(const Cat& oth)
{
	type = oth.type;
	*this->beg = *oth.beg;
	cout << "Cat copy assigment operator called" << endl;
	return (*this);
}

void Cat::makeSound() const
{
	cout << "The Cat sound" << endl;
}

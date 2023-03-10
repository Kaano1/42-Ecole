#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
	Animal	*kevser[4];
	int		max = 4;
	int		i;

	i = 0;
	while (i < max)
	{
		if (i < (2 / max))
			kevser[i] = new Dog();
		else
			kevser[i] = new Cat();
		i++;
	}

	i = 0;
	while(i < max)
	{
		kevser[i]->makeSound();
		i++;
	}
	i = 0;
	while(i < max)
	{
		delete kevser[i];
		i++;
	}
}


#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {


	const Animal* meta = new Animal(); 
	meta->makeSound();

	
	return 0;
}
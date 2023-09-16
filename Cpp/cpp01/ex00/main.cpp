#include "Zombie.hpp"

int	main(void)
{
	Zombie *first;
	first = newZombie("mehmet");
	Zombie *second;
	second = newZombie("ahmet");
    randomChump(second->getName());
    delete []second;
	delete []first;
}

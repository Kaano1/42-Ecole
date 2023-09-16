#include "HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::HumanB(string name)
{
	this->name = name;
}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon &club)
{
	this->gun = &club;
}

void	HumanB::attack(void)
{
	cout << name << " " << gun->getType() << endl; 
}

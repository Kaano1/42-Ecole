#include "Weapon.hpp"

string	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(string get)
{
	type = get;
}

Weapon::Weapon()
{
}

Weapon::Weapon(string name)
{
	this->type = name;
}
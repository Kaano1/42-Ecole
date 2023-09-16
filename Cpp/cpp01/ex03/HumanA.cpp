#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(string name, Weapon& gun) : weapon1(gun), name(name) {}

void	HumanA::attack(void)
{
	cout << name << " " << weapon1.getType() << endl; 
}

#include <iostream>
#include <string>
#include "Weapon.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;

class HumanB : Weapon
{
	private:
		Weapon* gun;
		string	name;
	public:
		HumanB();
		HumanB(string name);
		~HumanB();
		void	setWeapon(Weapon& club);
		void	attack(void);

};
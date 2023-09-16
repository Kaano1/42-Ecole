#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;


class HumanA : Weapon
{
	private:
		Weapon	&weapon1;
		string	name;
	public:
		HumanA(string name, Weapon& gun);
		string	getType() const;
		void	setType(string get);
		void	attack(void);
};

#endif
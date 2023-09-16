#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap()
{
	name = "";
	ClapTrap::name = "Inanc_clap_name";
	FragTrap::Hit = 100;
	FragTrap::damage = 30;
	ScavTrap::Energy = 50;

	cout << "Diamond Worked" << endl;
}

DiamondTrap::DiamondTrap(const string nick) : ClapTrap(nick)
{
	ClapTrap::name = nick + "_clap_name";
	FragTrap::Hit = 100;
	FragTrap::damage = 30;
	ScavTrap::Energy = 50;
	cout << "Diamond Worked" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& oth) : ClapTrap(oth.get_name() + "_clap_name")
{
	FragTrap::Hit = oth.Hit;
	FragTrap::damage = oth.damage;
	ScavTrap::Energy = oth.Energy;
	cout << "Copy Diamond Worked" << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "Diamond Deconstructer called" << endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& oth)
{
	Hit = oth.Hit;
	damage = oth.damage;
	Energy = oth.Energy;
	ClapTrap::name = oth.name;
	FragTrap::Hit = oth.Hit;
	FragTrap::damage = oth.damage;
	ScavTrap::Energy = oth.Energy;
	cout << "DiamondTrap Copy assigment Worked" << endl;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	cout << name << ClapTrap::name << endl;
	cout << "whoamI" << endl;
}

string	DiamondTrap::get_name() const
{
	return (name);
}

int	DiamondTrap::get_Hit() const
{
	return (Hit);
}

int	DiamondTrap::get_Energy() const
{
	return (Energy);
}

int	DiamondTrap::get_damage() const
{
	return (damage);
}

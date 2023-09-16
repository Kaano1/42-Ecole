#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		string name;
	public:
		DiamondTrap();
		DiamondTrap(const string nick);
		DiamondTrap(const DiamondTrap& oth);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap& oth);
		void whoAmI();
		string	get_name() const;
		int	get_Hit() const;
		int	get_Energy() const;
		int	get_damage() const;
};

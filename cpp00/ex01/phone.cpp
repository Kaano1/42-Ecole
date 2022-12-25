#include "phone.hpp"

int	ft_strlen(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(std::string s1, std::string s2)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(s1);
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && n - 1 > i)
		i++;
	return (s1[i] - s2[i]);
}

void	searching(Phonebook human, int many)
{
	int			i;
	std::string	get;

	i = 0;
	if (many >= 8)
		many = 8;
	std::cout << "First Name: ";
	std::cin >> get;
	human.book[human.i].set_first_name(get);
	std::cout << "Last Name: ";
	std::cin >> get;
	human.book[human.i].set_last_name(get);
	std::cout << "Nick Name: ";
	std::cin >> get;
	human.book[human.i].set_nickname(get);
	std::cout << "Phone Number: ";
	std::cin >> get;
	human.book[human.i].set_phone_number(get);
	while (i < many)
	{
		check_human();
		i++;
	}
}

int main(void)
{
	Phonebook	human;
	Contect		min;
	std::string	get;
	int			key;
	int			add;

	key = 1;
	human.i = 0;
	while (key != -1)
	{
		std::cout << "What is your process? ";
		std::cin >> get;
		if (ft_strcmp(get, "ADD"))
		{
			human.get_contect(add)
			std::cout << "First Name: ";
			std::cin >> get;
			human.book[human.i].set_first_name(get);
			std::cout << "Last Name: ";
			std::cin >> get;
			human.book[human.i].set_last_name(get);
			std::cout << "Nick Name: ";
			std::cin >> get;
			human.book[human.i].set_nickname(get);
			std::cout << "Phone Number: ";
			std::cin >> get;
			human.book[human.i].set_phone_number(get);
			std::cout << "Darkest Secret: ";
			std::cin >> get;
			human.book[human.i].set_darkest_secret(get);
			human.i++;
			add++;
			if (human.i == 8)
				human.i = 0;
		}
		else if (ft_strcmp(get, "SEARCH"))
			searching(human, add);
		else if (ft_strcmp(get, "EXIT"))
			key = -1;
	}
}
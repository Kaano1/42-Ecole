#include "Phonebook.hpp"

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

int	check_human(string first,string last,string nick,string number)
{
	return (0);
}

string	take_string()
{
	int		i;
	string	take;

	i = 1;
	while (i)
	{
		cin >> take;
		if (!take)
			i = 0;
		else
			cout << "Try again please!" << endl;
	}
	return (take);
}

void	show_page(Phonebook human, int many)
{
	int	i;

	i = 0;
	cout << "---------------------------" << endl;
	cout << "INDEX|FIRST NAME| LAST NAME| NICKNAME" << endl;
	cout << "--------------------------------------" << endl;
	while (i < many)
	{
		cout << "	" << book[i].append("|"); 
		cout << "	" << human.first_name.append("|"); 
		cout << "	" << human.last_name.append("|");
		cout << human.nickname.append("|");
	}
}

void	Phonebook::searching(int many)
{
	string	first;
	string	last;
	string	nick;
	string	number;
	int			i;

	
	i = 0;
	if (many >= 8)
		many = 8;
	show_page(human, many);
	cout << "which human?";
	first = take_string();//apend strw veya stdw
}

int main(void)
{
	Phonebook	human;
	Contect		min;
	string		get;
	int			key;
	int			add;
	int			count;

	key = 1;
	count = 0;
	add = 0;
	show_page(human, 0);
	exit (0);
	while (key != -1)
	{
		cout << "What do you want?(SEARCH, EXIT, ADD) ";
		cin >> get;
		if (ft_strcmp(get, "ADD"))
		{
			human.get_contect(add % 8);
			cout << "First Name: ";
			cin >> get;
			min.set_first_name(get);
			cout << "Last Name: ";
			cin >> get;
			min.set_last_name(get);
			cout << "Nick Name: ";
			cin >> get;
			min.set_nickname(get);
			cout << "Phone Number: ";
			cin >> get;
			min.set_phone_number(get);
			cout << "Darkest Secret: ";
			cin >> get;
			min.set_darkest_secret(get);
			add++;
		}
		else if (ft_strcmp(get, "SEARCH"))
			searching(human, add);
		else if (ft_strcmp(get, "EXIT"))
			key = -1;
	}
}
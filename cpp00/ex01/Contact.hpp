#ifndef CONTACT_HPP
#define  CONTACT_HPP

#include <iostream>
#include <string>
using	std::cin;
using	std::cout;
using	std::string;
using	std::endl;

class Contect
{
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	public:
		void	set_first_name(string str);
		void	set_last_name(string str);
		void	set_nickname(string str);
		void	set_phone_number(string str);
		void	set_darkest_secret(string str);
		void	get_first_name() const;
		void	get_last_name() const;
		void	get_nickname() const;
		void	get_phone_number() const;
		void	get_darkest_secret() const;

};


#endif
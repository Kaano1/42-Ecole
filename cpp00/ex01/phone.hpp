#include <iostream>
#include <string>
#include "contect.hpp"

class Contect
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void	set_first_name(std::string str);
		void	set_last_name(std::string str);
		void	set_nickname(std::string str);
		void	set_phone_number(std::string str);
		void	set_darkest_secret(std::string str);
		void	get_first_name();
		void	get_last_name();
		void	get_nickname();
		void	get_phone_number();
		void	get_darkest_secret();

};

void Contect::set_first_name(std::string str)
{
	this->first_name = str;
}

void Contect::set_last_name(std::string str)
{
	this->last_name = str;
}

void Contect::set_nickname(std::string str)
{
	this->nickname = str;
}

void Contect::set_phone_number(std::string str)
{
	this->phone_number = str;
}

void Contect::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

std::string Contect::get_first_name()
{
	return (this->first_name);
}

std::string Contect::get_last_name()
{
	return (this->last_name);
}

std::string Contect::get_nickname()
{
	return (this->nickname);
}

std::string Contect::get_phone_number()
{
	return (this->phone_number);
}

std::string Contect::get_darkest_secret()
{
	return (this->darkest_secret);
}


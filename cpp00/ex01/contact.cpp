
#include "Contact.hpp"


void Contect::set_first_name(string str)
{
	this->first_name = str;
}

void Contect::set_last_name(string str)
{
	this->last_name = str;
}

void Contect::set_nickname(string str)
{
	this->nickname = str;
}

void Contect::set_phone_number(string str)
{
	this->phone_number = str;
}

void Contect::set_darkest_secret(string str)
{
	this->darkest_secret = str;
}

string Contect::get_first_name() const
{
	return (this->first_name);
}

string Contect::get_last_name() const
{
	return (this->last_name);
}

string Contect::get_nickname() const
{
	return (this->nickname);
}

string Contect::get_phone_number() const
{
	return (this->phone_number);
}

string Contect::get_darkest_secret() const
{
	return (this->darkest_secret);
}
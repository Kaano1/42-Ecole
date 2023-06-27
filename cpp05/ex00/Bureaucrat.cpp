#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(150)
{
	cout << "Bureaucrat constructor is working" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& oth): name(oth.name), grade(oth.grade)
{
	cout << "Bureaucrat copy constructor is working" << endl;
}

Bureaucrat::~Bureaucrat();
{
	cout << "Bureaucrat is destroyed" << endl;
}

Bureaucrat	Bureaucrat::&operator=(const Bureaucrat &oth);
{
	cout << "Equal operator loading is work" << endl;
	this->grade = oth->grade;
	this->name = oth->name;
}

const string	Bureaucrat::getName(); const
{
	return (this->name);
}

int		Bureaucrat::getGrade(); const
{
	return (this->grade);
}

ostream	&Bureaucrat::opeartor<<(ostream &out, Bureaucrat &oth)
{
	out << oth->name << ", bureaucrat grade " << oth->grade << endl;
	return (out);
}
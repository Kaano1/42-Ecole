#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(150)
{
	cout << "Bureaucrat constructor is working" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& oth): name(oth.name), grade(oth.grade)
{
	cout << "Bureaucrat copy constructor is working" << endl;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat is destroyed" << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& oth)
{
    cout << "Equal operator loading is work" << endl;
    this->grade = oth.getGrade();
    return *this;
}

const string	Bureaucrat::getName() const
{
	return (this->name);
}

int		Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::setGrade(int be)
{
}


ostream	&operator<<(ostream &out, Bureaucrat &oth)
{
	out << oth.getName() << ", bureaucrat grade " << oth.getGrade() << endl;
	return (out);
}
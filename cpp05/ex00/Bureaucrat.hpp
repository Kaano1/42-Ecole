#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using	std::cout;
using	std::string;
using	std::endl;
using	std::ostream;

class Bureaucrat: public std::exception
{
	private:
		const string	name;
		int				grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& oth);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &oth);
		const string	getName(); const
		int				getGrade(); const
		ostream		&operator<<(ostream &out, const Bureaucrat &oth);
};

#endif
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using	std::cout;
using	std::string;
using	std::endl;
using	std::ostream;
using	std::exception;

class Bureaucrat
{
	private:
		const string	name;
		int				grade;
		class	GradeTooHighException: public exception
		{
			public:
				const char * what () const throw()
				{
					return "This number is highest";
				}
		};
		class	GradeTooLowException: public exception
		{
			public:
				const char * what () const throw()
				{
					return ("This number is lowest");
				}
		};
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& oth);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &oth);
		const string	getName() const;
		int				getGrade() const;
		void			setGrade(int be);
};

ostream		&operator<<(ostream &out, const Bureaucrat &oth);


#endif
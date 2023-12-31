#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const string	name;
	bool			signedStatus;
	const int		signGrade;
	const int		executeGrade;

public:
	Form();
	Form(const string &name, int signGrade, int executeGrade);
	~Form();
	
	class GradeTooHighException : public exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public exception
	{
		virtual const char *what() const throw();
	};

	string	getName() const;
	int		getExecuteGrade() const;
	bool	isSigned() const;
	int		getSignGrade() const;
	void	setSigned(bool signedStatus);
	void	beSigned(const Bureaucrat &bureaucrat);
};

ostream &operator<<(ostream &os, const Form &form);

#endif

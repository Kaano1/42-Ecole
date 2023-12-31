#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), signedStatus(false), signGrade(1), executeGrade(1) { }

Form::Form(const string &name, int signGrade, int executeGrade)
	: name(name), signedStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() { }

string	Form::getName() const { return name; }

bool	Form::isSigned() const { return signedStatus; }

int		Form::getSignGrade() const { return signGrade; }

int		Form::getExecuteGrade() const { return executeGrade; }

void	Form::setSigned(bool signedStatus) { this->signedStatus = signedStatus; }

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (!signedStatus) 
		bureaucrat.getGrade() <= signGrade ? signedStatus = true : throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

ostream	&operator<<(ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << ", Sign Grade: " << form.getSignGrade()
		<< ", Execute Grade: " << form.getExecuteGrade();
	return os;
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

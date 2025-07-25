/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:54:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 13:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* *********************** Constructors and Destructor ********************** */
AForm::AForm(void) : 
	_name("Nameless"),
	_target("Anonimus"),
	_signed(false),
	_gradeSign(20),
	_gradeExec(20)
{};

AForm::AForm(std::string name, std::string target, int gradeSign, int gradeExec) :
	_name(name),
	_target(target),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	if (gradeSign < _gradeMin)
		throw GradeTooHighException("Sign Grade");
	if (gradeSign > _gradeMax)
		throw GradeTooLowException("Sign Grade");
	if (gradeExec < _gradeMin)
		throw GradeTooHighException("Execution Grade");
	if (gradeExec > _gradeMax)
		throw GradeTooLowException("Execution Grade");
};

AForm::AForm(const AForm &other) : 
	_name(other._name),
	_target(other._target),
	_signed(other._signed),
	_gradeSign(other._gradeSign),
	_gradeExec(other._gradeExec)
{};

AForm::~AForm(void) {};

/* *************************** Assignment Operator ************************** */
AForm& AForm::operator=(const AForm &other)
{
	(void)other;
	return *this;
};

/* ***************************** Member Functions *************************** */
void		AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException("Bureaucrat's grade");
	_signed = true;
}

void		AForm::execute(Bureaucrat const &b) const
{
	if (!_signed)
		throw FormNotSigned();
	if (b.getGrade() > _gradeExec)
		throw GradeTooLowException("Bureaucrat's grade");
	beExecuted();
};

/* ********************************* Getters ******************************** */
std::string	AForm::getName(void) const { return _name; };

std::string	AForm::getTarget(void) const { return _target; };

bool		AForm::getSigned(void) const { return _signed; };

int			AForm::getGradeSign(void) const { return _gradeSign; };

int			AForm::getGradeExec(void) const { return _gradeExec; };

/* **************************** Overload Operator *************************** */
std::ostream& operator<<(std::ostream& os, const AForm &f)
{
	os << "AForm '" << f.getName() << (f.getSigned() ? "' is" : "' is not") 
		<< " signed. This form requires bureacrate level " << f.getGradeSign() 
		<< " or higher to sign it and bureaucrat level " 
		<< f.getGradeExec() << " or higher to execute it.";
	return os;
}
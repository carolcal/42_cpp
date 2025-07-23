/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:54:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 13:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* *********************** Constructors and Destructor ********************** */
Form::Form(void) : 
	_name("Nameless"), 
	_signed(false), 
	_gradeSign(20),
	_gradeExec(20)
{};

Form::Form(std::string name, int gradeSign, int gradeExec) :
	_name(name), 
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

Form::Form(const Form &other) : 
	_name(other._name),
	_signed(other._signed),
	_gradeSign(other._gradeSign),
	_gradeExec(other._gradeExec)
{};

Form::~Form(void) {};

/* *************************** Assignment Operator ************************** */
Form& Form::operator=(const Form &other)
{
	(void)other;
	return *this;
};

/* ***************************** Member Functions *************************** */
void		Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException("Bureaucrat's grade");
	_signed = true;
}

/* ********************************* Getters ******************************** */
std::string	Form::getName(void) const { return _name; };

bool		Form::getSigned(void) const { return _signed; };

int			Form::getGradeSign(void) const { return _gradeSign; };

int			Form::getGradeExec(void) const { return _gradeExec; };

/* **************************** Overload Operator *************************** */
std::ostream& operator<<(std::ostream& os, const Form &f)
{
	os << "Form '" << f.getName() << (f.getSigned() ? "' is" : "' is not") 
		<< " signed. This form requires bureacrate level " << f.getGradeSign() 
		<< " or higher to sign it and bureaucrat level " 
		<< f.getGradeExec() << " or higher to execute it.";
	return os;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:56:01 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 10:56:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* *********************** Constructors and Destructor ********************** */
Bureaucrat::Bureaucrat(void) : _name("Anonimus"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : 
	_name(name), 
	_grade(grade) 
	{};

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; };

Bureaucrat::~Bureaucrat(void) {};

/* *************************** Assignment Operator ************************** */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

/* ***************************** Member Functions *************************** */
void	Bureaucrat::incrementGrade(int amount)
{
	try
	{
		if (amount < 0)
			throw NegativeNumber();
		if (_grade - amount < _gradeMin)
			throw GradeTooHighException();
		_grade -= amount;
		std::cout << _name << "'s grade now is " << _grade << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error incrementing grade: " << e.what() << std::endl;
	}
	
}
void	Bureaucrat::decrementGrade(int amount)
{
	try
	{
		if (amount < 0)
			throw NegativeNumber();
		if (_grade + amount > _gradeMax)
			throw GradeTooLowException();
		_grade += amount;
		std::cout << _name << "'s grade now is " << _grade << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error decrementing grade: " << e.what() << std::endl;
	}
	
}

void    Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn’t sign " << f.getName() 
        << " because " << e.what() << std::endl;
    }
    
}

void		Bureaucrat::executeForm(AForm const &f)
{
	try
	{
		f.execute(*this);
		std::cout << _name << " executed " << f.getName() << " form." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error when executing Form " << f.getName() 
			<< ": " << e.what() << std::endl;
	}
	
}

/* ********************************* Getters ******************************** */
std::string		Bureaucrat::getName(void) const { return _name; };

int	Bureaucrat::getGrade(void) const { return _grade; };


/* **************************** Overload Operator *************************** */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
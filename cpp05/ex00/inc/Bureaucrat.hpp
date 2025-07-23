/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:35:31 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 10:35:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include "string"

# define RESET	"\033[0m"
# define PINK	"\033[35m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		static const int	_gradeMin = 1;
		static const int	_gradeMax = 150;

	public:
		/* ***** Constructors and Destructor **** */
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);

		/* ************* Operators ************** */
		Bureaucrat& operator=(const Bureaucrat &other);

		/* ********** Member Functins *********** */
		void		incrementGrade(int amount); //should actually decrement
		void		decrementGrade(int amount); //should actually increment

		/* ************* Getters *************** */
		std::string	getName(void) const;
		int			getGrade(void) const;

		/* ************* Exceptions ************ */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too hight! Please enter a smaller value to increment.";
				}

		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too low! Please enter a smaller value to decrement.";
				}
		};
		class NegativeNumber : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Negative value! Please enter a positive value.";
				}
		};
};

/* **************** Overload operator *************** */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
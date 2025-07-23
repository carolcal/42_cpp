/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:27:12 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 17:27:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include "iostream"
# include "string"

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string   _name;
		bool                _signed;
		const int			_gradeSign;
		const int			_gradeExec;
		static const int	_gradeMin = 1;
		static const int	_gradeMax = 150;

	public:
		/* ***** Constructors and Destructor **** */
		AForm(void);
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &other);
		~AForm(void);

		/* ******** Assignment Operator ********* */
		Form& operator=(const Form &other);

		/* ********** Member Functins *********** */
		void		beSigned(Bureaucrat &b);

		/* ************* Getters *************** */
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
	
		/* ************* Exceptions ************ */
		class GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooHighException(void)
				{
					_msg = "Grade is too hight!";
				}
				GradeTooHighException(const std::string &type)
				{
					_msg = type + " is too hight!";
				};
				virtual ~GradeTooHighException(void) throw() {};
				virtual const char* what() const throw()
				{
					return _msg.c_str();
				}

		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(void)
				{
					_msg = "Grade is too low!";
				};
				GradeTooLowException(const std::string &type)
				{
					_msg = type + " is too low!";
				};
				virtual ~GradeTooLowException(void) throw() {};
				virtual const char* what() const throw()
				{
					return _msg.c_str();
				}
		};
};

/* **************** Overload operator *************** */
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
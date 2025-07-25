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
		const std::string	_target;
		bool                _signed;
		const int			_gradeSign;
		const int			_gradeExec;
		static const int	_gradeMin = 1;
		static const int	_gradeMax = 150;

	protected:
		virtual void	beExecuted(void) const = 0;
	
	public:
		/* ***** Constructors and Destructor **** */
		AForm(void);
		AForm(std::string name, std::string target, int gradeSign, int gradeExec);
		AForm(const AForm &other);
		virtual ~AForm(void);

		/* ******** Assignment Operator ********* */
		AForm& operator=(const AForm &other);

		/* ********** Member Functins *********** */
		void		beSigned(Bureaucrat &b);
		void		execute(Bureaucrat const &b) const;

		/* ************* Getters *************** */
		std::string	getName(void) const;
		std::string	getTarget(void) const;
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
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form is not signed, please sign it with the proper Bureaucrat.";
				}
		};
};

/* **************** Overload operator *************** */
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
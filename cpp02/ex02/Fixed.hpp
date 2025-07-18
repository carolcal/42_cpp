/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:00 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/16 16:41:15 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

#define RESET	"\033[0m"
#define PINK	"\033[35m"

class Fixed
{
	private:
		int 				_fixedPoint;
		static const int	_fractionalBits = 8;

	public:
		/* ***** Constructors and Destructor **** */
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);
		
		/* ******** Assignment operator ********* */
		Fixed&	operator=(const Fixed& other);
		
		/* ******** Comparison operators ******** */
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		/* ******** Arithmetic operators ******** */
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		/* ******** Increment / Decrement ******* */
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		
		/* ***** Min / Max static functions ***** */
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		
		/* ******** Getters and Setters ********* */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* ******** Conversion functions ******** */
		float	toFloat(void) const;
		int		toInt(void) const;
};

/* **************** Overload operator *************** */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
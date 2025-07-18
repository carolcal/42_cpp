/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:00 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/16 14:05:02 by cayamash         ###   ########.fr       */
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
		Fixed(void); //Default Constructor
		Fixed(const Fixed& other); //Copy Constructor
		Fixed(const int num); // Parametrized Constructor (int)
		Fixed(const float num); //Parametrized Constructor (float)
		~Fixed(void); //Destructor
		
		Fixed& operator=(const Fixed& other); //Assignment Operator

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
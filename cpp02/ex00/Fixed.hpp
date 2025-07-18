/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:00 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/16 14:06:46 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define PINK	"\033[35m"

class Fixed
{
	private:
		int _fixedPoint;
		static const int _fractionalBits = 8;

	public:
		Fixed(void); //Default Constructor
		Fixed(const Fixed& other); //Copy Constructor
		Fixed& operator=(const Fixed& other); //Assignment Operator
		~Fixed(void); //Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
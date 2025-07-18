/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:40 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/16 14:00:09 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0) 
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
    _fixedPoint = num << _fractionalBits; // shift _fractionalBits to the left
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(num * ( 1 << _fractionalBits));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPoint = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	//std::cout << "toFloat member function called" << std::endl;
    float num = _fixedPoint / static_cast<float>(1 << _fractionalBits);
    return (num);
}

int		Fixed::toInt(void) const
{
	//std::cout << "toInt member function called" << std::endl;
    int num = _fixedPoint >> _fractionalBits;
    return (num);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

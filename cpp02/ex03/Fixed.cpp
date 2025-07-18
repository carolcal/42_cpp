/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:18:40 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 09:38:23 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* *********************** Constructors and Destructor ********************** */
Fixed::Fixed(void) : _fixedPoint(0) {};

Fixed::Fixed(const Fixed &other) : _fixedPoint(other._fixedPoint) {};

Fixed::Fixed(const int num)
{
    _fixedPoint = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
    this->_fixedPoint = roundf(num * ( 1 << _fractionalBits));
}

Fixed::~Fixed(void) {};

/* *************************** Assignment operator ************************** */
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fixedPoint = other.getRawBits();
    return *this;
}

/* ************************** Comparison operators ************************** */
bool Fixed::operator>(const Fixed& other) const
{
    return (this->_fixedPoint > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_fixedPoint < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_fixedPoint >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_fixedPoint <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_fixedPoint == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_fixedPoint != other.getRawBits());
}

/* ************************** Arithmetic operators ************************** */
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(_fixedPoint + other.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(_fixedPoint - other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((_fixedPoint * other.getRawBits()) / (1 << _fractionalBits));
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    if (other.getRawBits() == 0)
    {
        std::cout << "Can't divide by zero, returning empty: ";
        return (result);
    }
    result.setRawBits((_fixedPoint * (1 << _fractionalBits)) / other.getRawBits());
    return (result);
}

/* ************************** Increment / Decrement ************************* */
Fixed& Fixed::operator++()
{
    _fixedPoint++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _fixedPoint++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    _fixedPoint--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _fixedPoint--;
    return (temp);
}

/* *********************** Min / Max static functions *********************** */
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
    return ((a < b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
    return ((a < b) ? a : b);
}
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
    return ((a > b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
    return ((a > b) ? a : b);
}

/* *************************** Getters and Setters ************************** */
int Fixed::getRawBits(void) const
{
    return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}

/* ************************** Conversion functions ************************** */
float	Fixed::toFloat(void) const
{
    float num = _fixedPoint / static_cast<float>(1 << _fractionalBits);
    return (num);
}

int		Fixed::toInt(void) const
{
    int num = _fixedPoint >> _fractionalBits;
    return (num);
}

/* **************************** Overload operator *************************** */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

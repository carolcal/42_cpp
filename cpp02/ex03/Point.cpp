/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:30:22 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 11:46:17 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {};

Point::Point(const float x, const float y) : x(x), y(y) {};

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {};

Point::~Point(void) {};

Point	&Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Fixed Point::getX(void) const
{
    return x;
}

Fixed Point::getY(void) const
{
    return y;
}

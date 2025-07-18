/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:27:23 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 11:46:07 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed	x;
		const Fixed	y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		~Point(void);

		Point	&operator=(const Point &other);
		
		Fixed getX(void) const;
		Fixed getY(void) const;
};
	
Point	operator-(const Point &a, const Point &b);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
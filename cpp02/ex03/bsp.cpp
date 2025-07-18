/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:03:33 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/18 11:46:27 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point   operator-(const Point &a, const Point &b)
{
	return Point((a.getX() - b.getX()).toFloat(), (a.getY() - b.getY()).toFloat());
}

float dot(const Point &a, const Point &b)
{
	return (a.getX() * b.getX() + a.getY() * b.getY()).toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point	v0 = b - a;
    Point	v1 = c - a;
    Point	v2 = point - a;

	float	d00 = dot(v0, v0);
	float	d01 = dot(v0, v1);
	float	d11 = dot(v1, v1);
	float	d20 = dot(v2, v0);
	float	d21 = dot(v2, v1);
	
	float	denom = d00 * d11 - d01 * d01;
	float	s = (d11 * d20 - d01 * d21) / denom;
	float	t = (d00 * d21 - d01 * d20) / denom;

	bool inside = (s > 0) && (t > 0) && (s + t < 1);
	
	return inside;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:35:20 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/28 10:57:41 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T &value1, T &value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
T		min(T &value1, T &value2)
{
	return (value1 < value2) ? value1 : value2;
}

template <typename T>
T		max(T value1, T value2)
{
	return (value1 > value2) ? value1 : value2;
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:18:21 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/28 17:29:35 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>

template <typename T> 
class Array
{
	private:
		unsigned int	_len;
		T	*_array;
	
	public:
		/* ***** Constructors and Destructor **** */
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		~Array(void);

		/* ************* Operators ************* */
		Array &operator=(const Array &other);
		T &operator[](int index) const;

		/* ********** Member Functions ********* */
		unsigned int	size(void) const;
};

#endif
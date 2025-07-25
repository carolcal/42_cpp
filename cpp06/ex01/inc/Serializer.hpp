/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:04:05 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/25 16:43:27 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <stdint.h>

# include "Data.hpp"

class Serializer
{
	private:
		/* ***** Constructors and Destructor **** */
		Serializer(void);
		Serializer(const Serializer &other);
		~Serializer(void);

		/* ************* Operators ************** */
		Serializer& operator=(const Serializer &other);

	public:
		/* ********** Member Functins *********** */
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
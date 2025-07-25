/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:11:08 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/25 14:48:15 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* *********************** Constructors and Destructor ********************** */
Serializer::Serializer(void) {};

Serializer::Serializer(const Serializer &other) { *this = other; };

Serializer::~Serializer(void) {};

/* *************************** Assignment Operator ************************** */
Serializer& Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
};

/* ***************************** Member Functions *************************** */
uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
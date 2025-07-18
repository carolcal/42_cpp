/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:47:13 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 17:03:29 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): _type(type) {};

const std::string&	Weapon::getType()
{
    return (_type);
}


void    Weapon::setType(const std::string& value)
{
    _type = value;
}
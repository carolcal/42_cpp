/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:50:07 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 17:02:40 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string	_name;
        Weapon*		_weapon;

    public:
        HumanA(const std::string& name, Weapon& weapon);
		
        void attack();
};
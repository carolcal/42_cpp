/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:31:53 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 17:03:32 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string.h>

class Weapon
{
    private:
        std::string _type;
    
    public:
        Weapon(const std::string& type);
        
        const std::string& getType();
        void    setType(const std::string& value);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:46:42 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/11 12:56:23 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie(); //default constructor
        Zombie(const std::string& name); //parametrized constructor
        ~Zombie();

        void announce() const;
        void setName(const std::string& name);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:14:27 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 14:14:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>

# define RESET	"\033[0m"
# define PINK	"\033[35m"

class Animal
{
    protected:
        std::string _type;

    protected:
        /* ***** Constructors and Destructor **** */
        Animal(void);
        Animal(std::string type);
        Animal(const Animal &other);
        virtual ~Animal(void);

        /* ******** Assignment operator ********* */
        Animal& operator=(const Animal &other);

        /* ********** Method Functins *********** */
        std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
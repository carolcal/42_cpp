/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:04:20 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 15:04:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define RESET	"\033[0m"
# define PINK	"\033[35m"

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        /* ***** Constructors and Destructor **** */
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal(void);

        /* ******** Assignment operator ********* */
        WrongAnimal& operator=(const WrongAnimal &other);

        /* ********** Method Functins *********** */
        std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
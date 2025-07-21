/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:05:29 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 15:05:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        /* ***** Constructors and Destructor **** */
        WrongCat(void);
        WrongCat(const WrongCat &other);
        ~WrongCat(void);

        /* ******** Assignment operator ********* */
        WrongCat& operator=(const WrongCat &other);

        /* ********** Method Functins *********** */
		void	makeSound(void) const;
};

#endif
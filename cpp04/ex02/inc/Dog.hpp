/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:17:07 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 14:17:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		/* ***** Constructors and Destructor **** */
		Dog(void);
		Dog(const Dog &other);
		~Dog(void);

		/* ******** Assignment operator ********* */
		Dog& operator=(const Dog &other);

		/* ********** Method Functins *********** */
		void	makeSound(void) const;
		Brain*  getBrain(void) const;
};

#endif
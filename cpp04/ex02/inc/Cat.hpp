/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:44:25 by marvin            #+#    #+#             */
/*   Updated: 2025/07/21 14:44:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		/* ***** Constructors and Destructor **** */
		Cat(void);
		Cat(const Cat &other);
		~Cat(void);

		/* ******** Assignment operator ********* */
		Cat& operator=(const Cat &other);

		/* ********** Method Functins *********** */
		void	makeSound(void) const;
		Brain*  getBrain(void) const;
};

#endif
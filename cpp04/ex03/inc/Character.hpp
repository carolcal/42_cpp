/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:13:22 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/23 09:49:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"

# define RESET	"\033[0m"
# define PINK	"\033[35m"

class Character : public ICharacter
{
	private:
		std::string			_name;
		static const int	_inventorySize = 4;
		AMateria*			_inventory[_inventorySize];
		static const int	_floorSize = 42;
		AMateria*			_floor[_floorSize];

        /* ********** Method Functins *********** */
		bool	dropFloor(AMateria* m);
		void	initArrays(void);

	public:
		/* ***** Constructors and Destructor **** */
		Character(void);
		Character(std::string name);
		Character(const Character &other);
		~Character(void);
		
		/* ******** Assignment operator ********* */
		Character& operator=(const Character &other);

		/* ********** Method Functins *********** */
		std::string const & getName(void) const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
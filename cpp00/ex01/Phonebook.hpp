/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:35:59 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/08 19:07:15 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include "Contact.hpp"

class Phonebook
{
    private:
        Contact contacts[8];
		int		count;
        int		index;
    public:
		Phonebook();
        void add();
		void search();
		void searchId();
};
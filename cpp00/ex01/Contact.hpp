/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:18:50 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/08 19:07:21 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

class Contact 
{
    private:
        std::string	first_name;
        std::string	last_name;
		std::string	nickname;
        std::string	phone_number;
        std::string	darkest_secret;
	public:
		void        setFields();
        void        displayTableInfo(int i);
        void        displayDetailedInfo(int i);
};
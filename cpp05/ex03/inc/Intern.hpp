/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:04:45 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/24 18:57:03 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        /* ***** Constructors and Destructor **** */
        Intern(void);
        Intern(const Intern &other);
        ~Intern(void);

        /* ************* Operators ************** */
        Intern& operator=(const Intern &other);

        /* ********** Member Functins *********** */
        AForm&    makeForm(std::string name, std::string target);
};

#endif
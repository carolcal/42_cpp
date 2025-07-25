/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:27:22 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 17:27:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        /* ***** Constructors and Destructor **** */
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm(void);

        /* ******** Assignment Operator ********* */
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

        /* ********** Member Functins *********** */
        void    beExecuted(void) const;
};

#endif
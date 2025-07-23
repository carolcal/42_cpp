/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:27:19 by marvin            #+#    #+#             */
/*   Updated: 2025/07/23 17:27:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        /* ***** Constructors and Destructor **** */
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm(void);

        /* ******** Assignment Operator ********* */
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
}

#endif
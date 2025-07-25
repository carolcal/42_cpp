/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:55:48 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/25 17:57:24 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

# include <cstdlib>
# include <iostream>
# include <exception>
# include <ctime>

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# define RESET	"\033[0m"
# define PINK	"\033[35m"

Base	*generate(void);

void	identify(Base* p);

void	identify(Base& p);

#endif
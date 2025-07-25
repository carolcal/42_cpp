/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 04:58:16 by marvin            #+#    #+#             */
/*   Updated: 2025/07/25 04:58:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include "TypeIdentifier.hpp"
# include "Cast.hpp"

class ScalarConverter
{
	private:
		/* ************ Constructors ************ */
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		
		/* ************* Operators ************** */
		ScalarConverter& operator=(const ScalarConverter &other);
		
	public:
		/* ************* Destructor ************* */
		~ScalarConverter(void);

		/* ********** Member Functins *********** */
		static void	converter(std::string str);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:07:13 by cayamash          #+#    #+#             */
/*   Updated: 2025/08/07 11:47:31 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <stdexcept>

class RPN
{
	private:
		std::stack<int>	_nums;

		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		
		bool	isValidDigit(char curr, char next);
		bool	isValidOperator(char op);
		void	makeOperation(char op);
	
	public:
		RPN(void);
		~RPN(void);

		void	calculate(std::string expr);
};

#endif
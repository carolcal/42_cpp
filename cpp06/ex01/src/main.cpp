/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:50:04 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/25 16:26:20 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	std::cout << PINK << "* Creating Data *" << RESET << std::endl;
	Data		ptr;

	ptr.str = "* Quem tem luz própria jamais ficará na escuridão. *";
	std::cout << "Address: " << &ptr << std::endl;
	std::cout << "Value: " << ptr.str << std::endl;
	
	std::cout << PINK << "* Serializing *" << RESET << std::endl;
	uintptr_t serialize = Serializer::serialize(&ptr);
	std::cout << "Address: " << &serialize << std::endl;
	std::cout << "Value: " << serialize << std::endl;

	std::cout << PINK << "* Deserializing *" << RESET << std::endl;
	Data *deserialize = Serializer::deserialize(serialize);
	std::cout << "Address: " << deserialize << std::endl;
	std::cout << "Value: " << deserialize->str << std::endl;

	std::cout << PINK << "* Address and values will be the same, before and after *" << RESET << std::endl;
}
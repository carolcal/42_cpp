/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:06:33 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/14 15:26:41 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

void	open_file(std::ifstream& file1, std::string filename)
{
	file1.open(filename.c_str());
	if (!file1)
	{
		std::cout << "Error opening file." << std::endl;
		exit(2);
	}
	if (file1.peek() == EOF)
	{
		std::cout << "File is empty." << std::endl;
		exit(3);
	}
}

void create_new_file(std::ofstream& file2, std::string filename)
{
	std::size_t index_ext = filename.find_last_of(".");
	std::string new_filename = filename.substr(0, index_ext) 
		+ ".replace" + filename.substr(index_ext, std::string::npos);
	file2.open(new_filename.c_str());
}
void	copy_content(std::ifstream& file1, std::ofstream& file2, std::string s1, std::string s2)
{
	std::string content1;
	while (getline(file1, content1))
	{
		size_t index1 = 0;
		size_t index2 = content1.find(s1);
		std::string content2;
		while (index2 != std::string::npos)
		{
			std::string before = content1.substr(index1, index2 - index1);
			content2 += before + s2;
			index1 = index2 + s1.length();
			index2 = content1.find(s1, index1);
		}
		content2 += content1.substr(index1);
		file2 << content2 << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
		return (1);	
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file1;
	std::ofstream file2;
	
	open_file(file1, filename);
	create_new_file(file2, filename);
	copy_content(file1, file2, s1, s2);
	
	return (0);
}
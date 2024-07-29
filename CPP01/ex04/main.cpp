/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:06:59 by jsalaber          #+#    #+#             */
/*   Updated: 2024/07/29 10:19:59 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void replace(const std::string &filename, const std::string s1, const std::string s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return ;
	}
	inputFile.seekg(0, std::ios::end);
	if (inputFile.tellg() == 0)
	{
		std::cerr << "Error: File is empty." << std::endl;
		inputFile.close();
		return ;
	}
	inputFile.seekg(0, std::ios::beg);
	std::string outputFile = filename + ".replace";
	std::ifstream checkFile(outputFile.c_str());
	if (checkFile.is_open())
	{
		checkFile.close();
		outputFile += ".replace";
	}
	std::ofstream output(outputFile.c_str());
	if (!output.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		inputFile.close();
		return ;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line.empty())
		{
			output << std::endl;
			std::cout << "Error: line empty" << std::endl;
			continue ;
		}
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		output << line << std::endl;
	}
	inputFile.close();
	output.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments." << std::endl;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error: Empty string." << std::endl;
		return (1);
	}
	replace(filename, s1, s2);
	return (0);
}


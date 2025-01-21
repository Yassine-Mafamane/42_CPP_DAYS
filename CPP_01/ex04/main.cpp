/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 06:17:54 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/09 15:38:28 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replace_occurences(std::string& fileContent, std::string to_replace, std::string replacement)
{
	size_t	position = 0;

	if (to_replace == "")
		return ;

	position = fileContent.find(to_replace, position);
	while (position != std::string::npos)
	{
		fileContent.erase(position, to_replace.length());
		fileContent.insert(position, replacement);
		position += replacement.length();
		position = fileContent.find(to_replace, position);
	}
}


int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "This program takes 3 arguments : <filename> <String To Replace> <String To Replace By.>" << std::endl;
		return (1);
	}

	std::ifstream fileIn;
	std::ofstream fileOut;

	std::string to_replace = av[2];
	std::string replacement = av[3];

	fileIn.open(av[1]);
	if (fileIn.fail())
	{
		std::cerr << "An error has occured while oppening the given file!" << std::endl;
		return (1);
	}

	std::string outFileName;

	outFileName.append(av[1]);
	outFileName.append(".replace");

	fileOut.open(outFileName, std::ofstream::out | std::ofstream::trunc);
	if (fileOut.fail())
	{
		std::cerr << "An error has occured while oppening the replacement file!" << std::endl;
		return (1);
	}

	std::string fileContent;
	std::string line;

	while (getline(fileIn, line))
	{
		if (!fileIn.eof())
			line.append ("\n");
		fileContent.append (line);
	}

	fileIn.close ();

	replace_occurences(fileContent, to_replace, replacement);
	fileOut << fileContent;

	fileOut.close ();

	return 0;
}

/*
** EPITECH PROJECT, 2020
** UTILS_CPP
** File description:
** UTILS_CPP
*/

#include "../include/Utils.hpp"
#include <string>

std::vector <std::string> getFileContent(std::string pathToFile)
{
    std::string input = "";
    std::ifstream file(pathToFile);
	std::vector<std::string> content;

    if (!file)
        return content;
    while (std::getline(file, input))
	{
		content.push_back(input);
		input = "";
	}
    file.close();
	return content;
}
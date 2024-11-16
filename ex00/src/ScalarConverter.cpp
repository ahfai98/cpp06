/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:29:28 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 22:40:25 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cmath>
#include "../inc/ScalarConverter.hpp"

static int ft_stoi(const std::string &str)
{
	int num;
	std::stringstream ss(str);
	ss >> num;
	return (num);
}

static float ft_stof(const std::string &str)
{
	float num;
	std::stringstream ss(str);
	ss >> num;
	return (num);
}

static double ft_stod(const std::string &str)
{
	double num;
	std::stringstream ss(str);
	ss >> num;
	return (num);
}

enum literal_type {
	error,
	_pseudo_literal,
	_char,
	_int,
	_float,
	_double
};

static bool isChar(const std::string &literal)
{
	if (literal.length() != 1)
		return (false);
	if (literal.at(0) < std::numeric_limits<char>::min()
	 || literal.at(0) > std::numeric_limits<char>::max()
	 || isdigit(literal.at(0)))
			return (false);
	return (true);
}

static bool isInt(const std::string &literal)
{
	for (size_t i = (literal.at(0) == '-' ? 1 : 0); i < literal.length(); i++)
	{
		if (!isdigit(literal.at(i)))
			return (false);
	}
	return (true);
}

static bool isFloat(const std::string &literal)
{
	bool	found_point;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (literal.at(literal.length() - 1) != 'f')
		return (false);
	found_point = false;
	for (size_t i = 0; i < literal.length() - 1; i++)
	{
		if (literal.at(i) == '.' && found_point)
			return (false);
		else if (literal.at(i) == '.')
		{
			found_point = true;
			continue;
		}
		if (!isdigit(literal.at(i)))
			return (false);
	}
	return (true);
}

static bool isDouble(const std::string &literal)
{
	bool	found_point;

	found_point = false;
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal.at(i) == '.' && found_point)
			return (false);
		else if (literal.at(i) == '.')
		{
			found_point = true;
			continue ;
		}
		if (!isdigit(literal.at(i)))
			return (false);
	}
	return (true);
}

static bool isPseudoLiteral(const std::string &literal) {
	return (literal == "-inff" || literal == "+inff" || literal == "nanf"
			|| literal == "-inf" || literal == "+inf"  || literal == "nan");
}

static literal_type getType(const std::string &literal)
{
	// Array of check functions
	bool (*checkFuncs[])(const std::string &) = {isChar, isInt, isFloat, isDouble};
	literal_type types[] = {_char, _int, _float, _double};

	// Loop through each function and check if it returns true
	for (size_t i = 0; i < 4; ++i) {
		if (checkFuncs[i](literal))
			return (types[i]);
	}
	return (error); // Default case if no match found
}

static void literalChar(char ch)
{
	std::cout << "char: '" << ch << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

static void literalInt(int nbr)
{
	if (isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
	else
		std::cout << "char: Non displayable" << std::endl; 
	std::cout << "int: " << nbr << std::endl;
	if (nbr == std::floor(nbr))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

static void literalFloat(float nbr)
{
	if (isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	if (nbr == std::floor(nbr))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;
}

static void literalDouble(double nbr)
{
	if (isprint(nbr))
		std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	if (nbr == std::floor(nbr))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << nbr << std::endl;
}

static void pseudoLiteral(literal_type nbr_type, const std::string &pseudo_literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl; 
	if (nbr_type == _float)
	{
		std::cout << "float: " << pseudo_literal << std::endl;
		std::cout << "double: " << pseudo_literal.substr(0, pseudo_literal.length() - 1) << std::endl;
	}
	else if (nbr_type == _double)
	{
		std::cout << "float: " << pseudo_literal + "f" << std::endl;
		std::cout << "double: " << pseudo_literal << std::endl;
	}
}

ScalarConverter::ScalarConverter(){}

void ScalarConverter::convert(const std::string &literal)
{
	switch (getType(literal))
	{
		case _char:
			literalChar(literal.at(0));
			break;

		case _int:
			literalInt(ft_stoi(literal));
			break;

		case _float:
			if (isPseudoLiteral(literal))
				pseudoLiteral(_float, literal);
			else
				literalFloat(ft_stof(literal));
			break;

		case _double:
			if (isPseudoLiteral(literal))
				pseudoLiteral(_double, literal);
			else
				literalDouble(ft_stod(literal));
			break;

		default:
			std::cout << "Type not char, int, float or double." << std::endl;
			break;
	}
}
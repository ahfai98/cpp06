/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 21:28:24 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

using std::cerr;

int	main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
    {
        cerr << "Usage: ./convert <literal>" << "\n";
        return EXIT_FAILURE;
    }
    ScalarConverter::convert(argv[1]);
    return EXIT_SUCCESS;
}
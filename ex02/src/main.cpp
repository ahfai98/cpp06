/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 23:29:14 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../inc/Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::cerr << "No arguments needed. Just run ./program " << std::endl;
		return EXIT_FAILURE;
	}
	(void)argv;
	Base *base;
	std::cout << "TEST" << std::endl;
	base = generate();
	std::cout << std::endl;
	identify(base);
	identify(*base);
	delete base;
	return EXIT_SUCCESS;
}

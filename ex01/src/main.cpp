/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/16 23:00:31 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../inc/Serializer.hpp"

int main()
{
	// Create a Data object
	Data data(42, 3.14);

	// Serialize the pointer to data
	uintptr_t raw = Serializer::serialize(&data);

	// Deserialize the raw value back to a pointer
	Data *deserialized = Serializer::deserialize(raw);

	// Check if the original pointer and deserialized pointer are the same
	if (&data == deserialized)
	{
		std::cout << "Success: The deserialized pointer is equal to the original pointer!" << std::endl;
		std::cout << "Data x: " << deserialized->x << ", y: " << deserialized->y << std::endl;
	}
	else
	{
		std::cout << "Failure: The pointers do not match!" << std::endl;
	}
	return 0;
}

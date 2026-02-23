/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:56:52 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/23 13:25:04 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data d;
	Data *originPtr;
	Data *deserializePtr;
	uintptr_t raw;

	d.id = 42;
	d.name = "test";

	originPtr = &d;
	raw = Serializer::serialize(originPtr);
	deserializePtr = Serializer::deserialize(raw);

	std::cout << "Original Pointer: " << originPtr << std::endl;
	std::cout << "Serialized Value: " << std::hex << raw << std::dec << std::endl;
	std::cout << "Deserialize Pointer: " << deserializePtr << std::endl; 

	if (deserializePtr == originPtr)
		std::cout << "success" << std::endl;
	else
		std::cout << "fail" << std::endl;

	std::cout << "Data ID: " << deserializePtr->id << std::endl;
	std::cout << "Data Name: " << deserializePtr->name << std::endl;
}

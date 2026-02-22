/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 09:06:46 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/22 09:54:58 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void header(const std::string &input) {
	std::cout << "***** input: " << input  << std::endl;
}

void title(int id, const std::string &title) {
	std::cout << id << ") ========== " << title << std::endl;
}

void test_sec(const std::string &input) {
	header(input);
	ScalarConverter::convert(input);
	std::cout << std::endl;
} 

void test(void) {
	title(0, "PDF");
	test_sec("0");
	test_sec("nan");
	test_sec("42.0f");

	
}

int main(int argc, char *argv[]) {
	std::string input;

	if (argc != 2 || !argv[1][0])
	{
		std::cerr << "Usage: ./convertion <value>" << std::endl;
		return (1);
	}
	input = argv[1];
	if (input == "test")
	{
		test();
		return (0);
	}
	ScalarConverter::convert(argv[1]);
}
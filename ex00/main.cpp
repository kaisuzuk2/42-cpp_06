/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 09:06:46 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/22 12:16:30 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cfloat>
#include <sstream>

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

	title(1, "char test");
	test_sec("'a'");
	test_sec("'z'");
	test_sec("'\t'"); //Non displayable
	
	title(2, "int test");
	test_sec("97");
	test_sec("2147483647");
	test_sec("2147483648"); // overflow
	test_sec("-2147483648");
	test_sec("-2147483649"); // underflow

	title(3, "float test");
	test_sec("97.0f");
	test_sec("123.45f");
	test_sec("3.40282e+38");
	test_sec("-3.40282e+38"); // overflow
	test_sec("3.40283e+38");
	test_sec("-3.40283e+38"); // underflow

	title(4, "double test");
	test_sec("42e+42");
	test_sec("123.45");
	test_sec("1.7976931348623157e+308");
	test_sec("-1.7976931348623157e+308");
	test_sec("1.7976931348623157e+420"); // overflow
	test_sec("-1.797693134862315799e+420"); // underflow

	title(5, "pseudo test");
	test_sec("inff");
	test_sec("-inff");
	test_sec("inf");
	test_sec("-inf");
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
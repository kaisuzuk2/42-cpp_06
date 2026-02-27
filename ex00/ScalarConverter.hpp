/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:10:39 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/27 11:25:30 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <cerrno>
#include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter();
		static const int kCharSize = 255;
		enum ValType {
			T_CHAR, 
			T_INT,
			T_FLOAT,
			T_DOUBLE,
			T_PSEUDO,
			T_INVALID
		};
		static ValType detectType(const std::string &);
		static bool isCharVal(const std::string &);
		static bool isPseudoVal(const std::string &);
		static bool isFloatVal(const std::string &);
		static bool isDoubleVal(const std::string &);
		static bool isIntVal(const std::string &);
		static int parseInt(const std::string &);
		static float parseFloat(const std::string &);
		static double parseDouble(const std::string &);
		static void printFromChar(char c);
		static void printFromInt(int i);
		static void printFromFloat(float f);
		static void printFromDouble(double d);
		static void printImpossible();
		static void printPseudo(const std::string &);
	public:
		static void convert(const std::string &);
};

#endif
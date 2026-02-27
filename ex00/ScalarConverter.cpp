/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:10:44 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/27 11:25:58 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharVal(const std::string &val) {
	return (val.size() == 1 && !isdigit(val[0]));
}

bool ScalarConverter::isPseudoVal(const std::string &val) {
	return (val == "nan" || val == "inf" || val == "-inf" || 
				val == "nanf" || val == "inff" || val == "-inff");
}

bool ScalarConverter::isFloatVal(const std::string &val) {
	std::string core;
	char *end;
	float tmp;

	if (val.size() < 2 || val[val.size() - 1] != 'f')
		return (false);
	core = val.substr(0, val.size() - 1);
	end = 0;
	tmp = std::strtod(core.c_str(), &end);
	if (end == core.c_str() || *end != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::isDoubleVal(const std::string &val) {
	char *end;
	double tmp;

	end = 0;
	if (val.find('.') == std::string::npos && val.find('e') == std::string::npos 
			&& val.find('E') == std::string::npos)
	return (false);
	tmp = std::strtod(val.c_str(), &end);
	if (end == val.c_str() || *end != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::isIntVal(const std::string &val) {
	char *end;
	long int tmp;
	
	end = 0;
	tmp = std::strtol(val.c_str(), &end, 10);
	if (end == val.c_str() || *end != '\0')
		return (false);
	if (tmp > std::numeric_limits<int>::max() || 	
			tmp < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

ScalarConverter::ValType ScalarConverter::detectType(const std::string &val) {
	if (isCharVal(val))
		return (T_CHAR);
	if (isPseudoVal(val))
		return (T_PSEUDO);
	if (isIntVal(val))
		return (T_INT);
	if (isFloatVal(val))
		return (T_FLOAT);
	if (isDoubleVal(val))
		return (T_DOUBLE);
	return (T_INVALID);
}

int ScalarConverter::parseInt(const std::string &val) {
	char *end;

	end = 0;
	long int res = std::strtol(val.c_str(), &end, 10);
	return (static_cast<int>(res));
}

float ScalarConverter::parseFloat(const std::string &val) {
	char *end;
	std::string core;

	end = 0;
	core = val.substr(0, val.size() - 1);
	double res = std::strtod(core.c_str(), &end);
	return (static_cast<float>(res));
}

double ScalarConverter::parseDouble(const std::string &val) {
	char *end;

	end = 0;
	double res = std::strtod(val.c_str(), &end);
	return (res);
}

void ScalarConverter::printFromChar(char c) {
	std::cout << "char: ";
	if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) <<  static_cast<double>(c) << std::endl;
}

void ScalarConverter::printFromInt(int i) {
	std::cout << "char: ";
	if (i < 0 || i > kCharSize)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(i) << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" <<  std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFromFloat(float f) {
	std::cout << "char: ";
	if (f < 0 || f > kCharSize) 
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(f))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout <<  "\'" << static_cast<char>(f) << "\'"  << std::endl;
	
	std::cout << "int: ";
	if (f > std::numeric_limits<int>::max() || 
		f < std::numeric_limits<int>::min())
		std::cout << "i" << std::endl;
	else
		std::cout <<  static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " <<  f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1)  << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printFromDouble(double d) {
	std::cout << "char: ";
	if (d < 0 || d > kCharSize)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(d))
		std::cout << "Non displayable" << std::endl;
	else 
		std::cout <<  "\'" << static_cast<char>(d) <<  "\'" << std::endl;

	std::cout << "int: ";
	if (d > std::numeric_limits<int>::max() ||
		d < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else 
		std::cout << static_cast<int>(d)<< std::endl;
	
	std::cout <<  std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout  << std::fixed << std::setprecision(1) << "double: " <<  d << std::endl;
}

void ScalarConverter::printImpossible(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl; 
}

void ScalarConverter::printPseudo(const std::string &val) {
	if (val == "nan" || val == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}

	if (val == "inf" || val == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}	

	if (val == "-inf" || val == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &val) {
	ValType type = detectType(val);
	char c;
	long i;
	float f;
	double d;

	switch (type) {
		case T_CHAR: 
			c = val[0];
			printFromChar(c);
			break;
		case T_INT: 
			i = parseInt(val);
			printFromInt(i);
			break;
		case T_FLOAT:
			f = parseFloat(val);
			printFromFloat(f);
			break;
		case T_DOUBLE:
			d = parseDouble(val);
			printFromDouble(d);
			break;
		case T_PSEUDO:
			printPseudo(val);
			break;
		case T_INVALID: 
			printImpossible();
			break;
	}
}
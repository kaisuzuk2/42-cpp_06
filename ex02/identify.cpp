/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:32:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/23 08:47:00 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch(...) {}
	try {
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch(...) {}
	try {
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
}
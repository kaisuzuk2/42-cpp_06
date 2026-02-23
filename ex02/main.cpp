/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:20:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/23 13:25:57 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "generate.hpp"
#include "identify.hpp"

int main(void) {
	std::srand(std::time(0));

	std::cout << "---------- test identify(Base *) ----------" << std::endl; 
	for (int i = 0; i < 5; i++) {
		Base *ptr = generate();
		std::cout << "*** test " << i << ": ";
		identify(ptr);
	}

	std::cout << "---------- test identify(Base &) ----------" << std::endl;
	for (int i = 0; i < 5; i++) {
		Base *ptr = generate();
		std::cout << "*** test" << i << ": ";
		identify(*ptr);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:25:24 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/23 08:32:08 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate.hpp"

Base *generate(void) {
	int random;

	std::srand(std::time(0));
	random = std::rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else 
		return (new C);
}
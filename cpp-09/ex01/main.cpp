/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:12:07 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/11 15:28:18 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int args, char **argv)
{
	if (args != 2)
	{
		std::cout << "<./RPN> <reverse polish notation>" << std::endl;
		return (-1);
	}
	RPN a(argv[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:47:53 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/11 14:11:02 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int args, char **argv)
{
	if (args != 2)
	{
		std::cout << "<./btc> <input_file>" << std::endl;
		return (-1);
	}
	Data a(argv[1]);
	return (0);
}

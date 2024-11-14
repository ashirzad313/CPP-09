/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:48:40 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/14 14:42:42 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int args, char **argv)
{
	if (args < 3 || args > 3001)
	{
		std::cout << "invalid format" << std::endl;
		return (-1);
	}
	PMergeMe Johnson(&argv[1]);
	return (0);
}

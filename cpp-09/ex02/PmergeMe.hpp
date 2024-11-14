/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:04:47 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/14 17:59:47 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PMERGE_HPP__
#define __PMERGE_HPP__

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <deque>

class PMergeMe
{
	private :
		char	**_argv;
		std::vector<int> _vector;
		std::deque<int> _deque;
	public :
		// Orthodox Cononical Form
		PMergeMe(void);
		PMergeMe(char **argv);
		PMergeMe(PMergeMe &copy);
		PMergeMe &operator=(PMergeMe &other);
		~PMergeMe(void);

		//methods //
		typedef std::vector<int>::iterator iterator;
		void	parsing(void);
		void	sortVector(int pair_level);
		void	swap_pair(iterator it, int pair_level);
		long	jacobsthal(long n);
		bool	comp(iterator lv, iterator rv){return *lv < *rv;}

		void	ft_print();
};

#endif // __PMERGE_HPP__

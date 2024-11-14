/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:36 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/14 18:00:37 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe(void) : _argv(NULL){}

PMergeMe::PMergeMe(char **argv) : _argv(argv)
{
	parsing();
	sortVector(1);
	// ft_print();
}

PMergeMe::PMergeMe(PMergeMe &copy) : _argv(copy._argv), _vector(copy._vector), _deque(copy._deque)
{
	*this = copy;
}

PMergeMe &PMergeMe::operator=(PMergeMe &other)
{
	if (this == &other)
		return (*this);
	this->_argv = other._argv;
	this->_vector = other._vector;
	this->_deque = other._deque;
	return (*this);
}

PMergeMe::~PMergeMe(void) {}


// methods //

void	PMergeMe::parsing(void)
{
	int i = 0, j = 0;
	while (_argv[i])
	{
		j = 0;
		if (isdigit(_argv[i][j]) == 0)
		{
			std::cout << "Error" << std::endl;
			exit(-1);
		}
		_vector.push_back(atoi(_argv[i]));
		_deque.push_back(atoi(_argv[i]));
		i++;
	}
}

void	PMergeMe::swap_pair(iterator it, int pair_level)
{
	iterator first = next(it, -pair_level + 1);
	iterator end = next(first, pair_level);

	while (first != end)
	{
		std::iter_swap(first, next(first, pair_level));
		first++;
	}
}

void	PMergeMe::sortVector(int pair_level)
{
	// divide into pairs
	int pair_unit_nbr = _vector.size() / pair_level;
	bool is_odd = pair_unit_nbr % 2;

	iterator first = _vector.begin();
	iterator last = next(_vector.begin(), pair_level * pair_unit_nbr);
	iterator end = next(last, -(is_odd * pair_level));
	if (pair_unit_nbr < 2)
		return ;

	int jump = 2 * pair_level;
	for (iterator it = first; it != end; std::advance(it, jump))
	{
		iterator this_pair = next(it, pair_level - 1);
		iterator next_pair = next(it, pair_level * 2 - 1);
		if (*this_pair > *next_pair)
			swap_pair(this_pair, pair_level);
	}
	sortVector(pair_level * 2);

	// insert the a's into main-chain and b's into pend-chain
	std::vector<iterator> main;
	std::vector<iterator> pend;

	main.insert(pend.end(), next(_vector.begin(), pair_level - 1));
	main.insert(main.end(), next(_vector.begin(), pair_level * 2 - 1));


	for (int i = 4; i <= pair_unit_nbr; i += 2)
	{
		pend.insert(pend.end(), next(_vector.begin(), pair_level * (i - 1) - 1));
		main.insert(main.end(), next(_vector.begin(), pair_level * i - 1));
	}

	// binary search using jacobstahl
	int	prev_jacobsthal = jacobsthal(2);
	int inserted_numbers = 0;

	for (int k = 0;; k++)
	{
		int curr_jacobsthal = jacobsthal(k + 1);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
		if (jacobsthal_diff > (int)pend.size())
			break ;
		int nbr_of_times = jacobsthal_diff;
		typename std::vector<iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
		typename std::vector<iterator>::iterator bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers);
		while (nbr_of_times)
		{
			typename std::vector<iterator>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, comp);
			typename std::vector<iterator>::iterator inserted = main.insert(idx, *pend_it);
			nbr_of_times--;
			

		}
	}

}

long	PMergeMe::jacobsthal(long n)
{
	if (n <= 1)
		return (n);
	return jacobsthal(n - 1) + (2 * jacobsthal(n - 2));
}


void	PMergeMe::ft_print(void)
{
	int i = 0;
	std::cout << "Before : ";
	while (_argv[i])
		std::cout << _argv[i++] << " ";
	std::cout << std::endl;

	std::cout << "After : ";
	for (const auto &it : _vector)
		std::cout << it << " ";
	std::cout << std::endl;
}

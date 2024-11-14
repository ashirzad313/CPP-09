/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:04:11 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/12 19:59:27 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

class RPN
{
	private :
		std::string _op;
		std::stack<int> _stack;
	public :
		RPN(void);
		RPN(std::string op);
		RPN(RPN &copy);
		RPN &operator=(RPN &other);
		~RPN(void);

		//methods
		void 	skip(std::string &str);
		int		getResult(std::string ope);
		bool	isNumber(std::string str);
		int		getTop(void);
};

#endif // __RPN_HPP__ //


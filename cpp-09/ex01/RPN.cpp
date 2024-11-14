/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:07:15 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/12 20:00:40 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _op("default") {}

RPN::RPN(std::string op) : _op(op)
{
	std::stringstream ss(op);
	std::stringstream ss1(op);
	std::string word;
	int count = 0;
	int i = 0;

	while (!ss.eof())
	{
		std::getline(ss, word, ' ');
		skip(word);
		if (!word.empty())
			count++;
	}
	std::string list[count];
	while (!ss1.eof())
	{
		std::getline(ss1, word, ' ');
		skip(word);
		if (!word.empty())
			list[i++] = word;
	}
	for (int i = 0; i < count; i++)
	{
		if (isNumber(list[i]))
			this->_stack.push(std::stoi(list[i]));
		else
			this->_stack.push(getResult(list[i]));
	}
	std::cout << getTop() << std::endl;
}

RPN::RPN(RPN &copy) : _op(copy._op), _stack(copy._stack)
{
	*this = copy;
}

RPN &RPN::operator=(RPN &other)
{
	if (this == &other)
		return (*this);
	this->_stack = other._stack;
	return (*this);
}

RPN::~RPN(void) {}


// methods

int	RPN::getResult(std::string ope)
{
	int a = getTop();
	this->_stack.pop();
	int b = getTop();
	this->_stack.pop();

	if (ope == "+")
		return (a + b);
	else if (ope == "-")
		return (b - a);
	else if (ope == "*")
		return (a * b);
	else if (ope == "/")
		return (a / b);
	return (0);
}

bool	RPN::isNumber(std::string str)
{
	if (str == "-")
		return (0);
	for (int i = 0; i < (int)str.length(); i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (0);
	}
	return (1);
}

int RPN::getTop(void)
{
	if (this->_stack.empty())
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	return (this->_stack.top());
}

void	RPN::skip(std::string &str)
{
	int first_of = str.find_first_not_of(' ');
	str.erase(0, first_of);
	int last_of = str.find_last_not_of(' ');
	str = str.substr(0, last_of + 1);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:45:44 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/11 13:50:51 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <thread>
#include <chrono>

class Data
{
	private :
		std::string	_inputFile;
		std::map<std::string, double> _dataBase;
	public :
		// Orthodox Canonical Form
		Data(void);
		Data(std::string file);
		Data(Data &copy);
		Data &operator=(Data &other);
		~Data(void);

		//main methods
		void readDB(void);
		void inputFile(void);
		bool	isValidDate(std::string date);
		int	isValidValue(std::string date);
		double	getPrice(int year, int month, int day);

		//utils
		std::string	*split(std::string str, char d);
		std::string skip(std::string str);
		int			array_len(std::string *array);
};

#endif // __BITCOINEXCHANGE_HPP__ //

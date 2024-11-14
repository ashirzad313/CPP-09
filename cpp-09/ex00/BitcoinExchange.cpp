/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:20:16 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/11 14:42:33 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constrcutors and Destrcutors

Data::Data(void) {}

Data::Data(std::string file) : _inputFile(file)
{
	Data::readDB();
	Data::inputFile();
}

Data::Data(Data &copy) : _dataBase(copy._dataBase)
{
	*this = copy;
}

Data &Data::operator=(Data &other)
{
	if (this == &other)
		return (*this);
	this->_dataBase = other._dataBase;
	return (*this);
}

Data::~Data(void) {}


// methods

void	Data::readDB()
{
	std::string	line;
	std::fstream f_open("data.csv");

	if (!f_open.is_open())
	{
		std::cout << "data.csv Could not be found" << std::endl;
		exit(-1);
	}
	std::getline(f_open, line);
	while (std::getline(f_open, line))
	{
		int pos = line.find(',');
		std::string key = line.substr(0, pos);
		double value = std::stod(line.substr(pos + 1));
		this->_dataBase[key] = value;
	}
}

void	Data::inputFile()
{
	std::string	line;
	std::fstream inputFile(this->_inputFile);

	if (!inputFile.is_open())
	{
		std::cout << this->_inputFile << " Could not be opened" << std::endl;
		exit(-1);
	}
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::string *list = Data::split(line, '|');
		if (array_len(list) != 2 || !isValidDate(list[0]))
			std::cout << "Error: bad input => " << line << std::endl;
		else if (isValidValue(list[1]) == -1)
			std::cout << line << " : bad input " << std::endl;
		else if (isValidValue(list[1]) == -2)
			std::cout << "Error: not a positive number. " << std::endl;
		else if (isValidValue(list[1]) == -3)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			std::string *date = Data::split(list[0], '-');
			int year = std::stoi(date[0]);
			int month = std::stoi(date[1]);
			int day = std::stoi(date[2]);
			double value = std::stod(list[1]);
			std::cout << list[0] << " => " << value << " = " << value * getPrice(year, month, day) << std::endl;
		}
		delete []list;
	}
}

std::string	*Data::split(std::string str, char d)
{
	int	count_words = std::count(str.begin(), str.end(), d) + 1;
	std::string	*ptr = new std::string[count_words];
	int i;

	for (i = 0; i < count_words - 1; i++)
	{
		int pos = str.find(d);
		ptr[i] = str.substr(0, pos);
		ptr[i] = skip(ptr[i]);
		str.erase(0, pos + 1);
	}
	ptr[i] = str;
	ptr[i] = skip(ptr[i]);
	return (ptr);
}

std::string Data::skip(std::string str)
{
	int first_of = str.find_first_not_of(' ');
	str.erase(0, first_of);
	int last_of = str.find_last_not_of(' ');
	str = str.substr(0, last_of + 1);
	return (str);
}

int	Data::array_len(std::string *array)
{
	int	i = 0;
	while (!array[i].empty())
		i++;
	return (i);
}

double	Data::getPrice(int year, int month, int day)
{
	std::ostringstream date;
	std::string			date_str;

	for (int y = year; y >= 2009; y--)
	{
		for (int m = month; m > 0; m--)
		{
			for (int d = day; d > 0; d--)
			{
				if (this->_dataBase.find(date_str) != this->_dataBase.end())
					return (this->_dataBase[date_str]);
				date << y << "-";
				date << std::setw(2) << std::setfill('0') << m << "-";
				date << std::setw(2) << std::setfill('0') << d;
				date_str = date.str();
				date.str("");
			}
		}
	}
	return (0);
}

bool Data::isValidDate(std::string date)
{
	std::string *list = split(date, '-');
	int exit = 1;
	if (array_len(list) != 3)
		exit = 0;
	else if (list[0] < "2009" || list[0] > "2022")
		exit = 0;
	else if (list[1] > "12" || list[1] == "0")
		exit = 0;
	else if (list[2] > "31" || list[2] == "0")
		exit = 0;
	delete []list;
	return (exit);
}

int	Data::isValidValue(std::string price)
{
	if (std::count(price.begin(), price.end(), '.') > 1 || std::count(price.begin(), price.end(), '-') > 1)
		return (-1);
	for (int i = 0; i < (int)price.length(); i++)
	{
		if ((price[i] < '0' || price[i] > '9') && price[i] != '.' && price[i] != '-')
			return (-1);
	}
	if (std::stol(price) < 0)
		return (-2);
	else if (std::stol(price) > 1000)
		return (-3);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:56:47 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/08 13:34:34 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>

# define CSV_FILE "data.csv"

enum ErrorType
{
	ERROR_OVERFLOW,
	ERROR_NEGATIVE,
	ERROR_INVALID, 
	VALID
};

class BitcoinExchange
{
	public:
		typedef std::map<std::string, float> Database;
		typedef std::map<std::string, float>::iterator Iterator;
		
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange(void);
		
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void saveDatabase(std::ifstream& file);
		void printValues(std::ifstream& file);
	private:
		Database _database;
		Database _inputDatabase;
};

bool invalidDate(const std::string& date);
ErrorType invalidValue(const std::string& value, const bool& error);
bool wrongYear(const std::string& date);
float getResult(BitcoinExchange::Database& database, std::string& date, float& btc);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:44:36 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 03:02:45 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data* important = new Data;
	
	important->importantData = "Here there is some important data!";
	
	uintptr_t serialized = Serializer::serialize(important);
	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout << "Original Data: " << important->importantData << std::endl;
	std::cout << "Serialized Data: " << serialized << std::endl;
	std::cout << "Deserialized Data: " << deserialized->importantData << std::endl;
	
	delete important;
	return 0;
}
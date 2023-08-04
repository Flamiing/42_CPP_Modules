/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:45:10 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 03:03:21 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATOR */
Serializer::Serializer(void)
{
	
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;	
}

Serializer::~Serializer(void)
{
	
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

/* MEMBER FUNCTION */
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
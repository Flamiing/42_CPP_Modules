/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:14:17 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/05 17:31:43 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <iostream>
#include <exception>

template<typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size)
{
	unsigned int pos = 0;

	while (pos < this->_size)
	{
		this->_array[pos] = other._array[pos];
		pos++;
	}
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	unsigned int pos = 0;
	
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[this->_size];
		while (pos < this->_size)
		{
			this->_array[pos] = other._array[pos];
			pos++;
		}
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= this->size())
		throw std::out_of_range("Index out of bounds");
	else
		return this->_array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index < 0 || index >= this->size())
		throw std::out_of_range("Index out of bounds");
	else
		return this->_array[index];
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return this->_size;
}

#endif
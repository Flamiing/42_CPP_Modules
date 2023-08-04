/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:49:16 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 14:13:40 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
T min(T& value1, T& value2)
{
	if (value1 < value2)
		return value1;
	else
		return value2;
}

template <typename T>
T max(T& value1, T& value2)
{
	if (value1 > value2)
		return value1;
	else
		return value2;
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:41:20 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 14:56:35 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename Function>
void iter(T* array, size_t len, Function function)
{
	size_t pos = 0;

	while (pos < len)
	{
		function(array[pos]);
		pos++;
	}
}

#endif
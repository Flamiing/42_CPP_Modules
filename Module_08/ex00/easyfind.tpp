/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:00:44 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/05 23:35:56 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template<typename T>
int easyfind(T& container, int toFind)
{
	typename T::iterator result = std::find(container.begin(), container.end(), toFind);
	if (result != container.end())
		return *result;
	else
		return -1;
}

#endif
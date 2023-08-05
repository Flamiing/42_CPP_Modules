/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:00:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/05 23:23:17 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <deque>
# include <set>
# include <vector>
# include <list>

template<typename T>
int easyfind(T& container, int firstOcurrence);

# include "easyfind.tpp"

#endif
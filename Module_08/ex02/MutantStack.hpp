/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:41:14 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/07 12:30:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iterator>
# include <algorithm>
# include <stack>
# include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;

		MutantStack(void);
		MutantStack(const MutantStack& other);
		~MutantStack(void);
		
		MutantStack& operator=(const MutantStack& other);

		iterator begin(void);
		iterator end(void);
};

# include "MutantStack.tpp"

#endif
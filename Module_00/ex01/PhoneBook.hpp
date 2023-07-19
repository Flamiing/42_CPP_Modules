/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:39 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 01:08:35 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int	_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
};

#endif
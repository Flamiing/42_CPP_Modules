/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:17 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 21:17:58 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int	_exist;
	public:
		Contact(void);
		~Contact(void);
		void	setFirstName(void);
		void	setLastName(void);
		void	setNickname(void);
		void	setPhoneNumber(void);
		void	setDarkestSecret(void);
		void	printContact(void);
		void	displayFirstName(void);
		void	displayLastName(void);
		void	displayNickname(void);
		int	exist(void);
};

#endif
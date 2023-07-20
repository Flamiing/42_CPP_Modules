/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:12:07 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 12:00:23 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKUTILS_HPP
# define PHONEBOOKUTILS_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

std::string	getInput(void);
void	displayContacts(Contact contacts[]);

#endif
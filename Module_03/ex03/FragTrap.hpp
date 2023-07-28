/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:07:13 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/28 13:57:11 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);	
		FragTrap(std::string name);	
		FragTrap(const FragTrap& other);	
		~FragTrap(void);

		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys(void);
};

#endif
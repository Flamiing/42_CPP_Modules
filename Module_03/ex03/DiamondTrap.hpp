/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:41:47 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/22 02:42:35 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap
{
	public:
		DiamondTrap(void);	
		DiamondTrap(std::string name);	
		DiamondTrap(const FragTrap& other);	
		~DiamondTrap(void);

		using ClapTrap::operator=;
};

#endif
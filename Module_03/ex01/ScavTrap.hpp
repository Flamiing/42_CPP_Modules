/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:06:56 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/27 18:33:58 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap(void);
		
		ScavTrap& operator=(const ScavTrap& other);

		void guardGate(void);
		void attack(const std::string& target);
		using ClapTrap::takeDamage;
		using ClapTrap::beRepaired;
};

#endif
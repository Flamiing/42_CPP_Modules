/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:41:47 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/28 13:57:05 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap(void);

		DiamondTrap& operator=(const DiamondTrap& other);

		void whoAmI(void);
		using FragTrap::_hitPoints;
		using ScavTrap::_energyPoints;
		using FragTrap::_attackDamage;
		using ScavTrap::attack;
	private:
		std::string _name;
};

#endif
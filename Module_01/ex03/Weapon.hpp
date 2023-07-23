/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:41:06 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 23:41:57 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string weaponType);
		~Weapon(void);
		const std::string&	getType(void) const;
		void	setType(std::string new_type);
};

#endif
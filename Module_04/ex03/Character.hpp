/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:07:01 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/27 14:41:27 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "info.hpp"
# include <iostream>

class Character : public ICharacter
{
	public:
		Character(void);
		Character(const std::string name);
		Character(const Character& other);
		virtual ~Character(void);
		
		Character& operator=(const Character& other);
		
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	private:
		std::string _name;
		AMateria* _inventory[4];
		AMateria** _unequipped;
		int _unequippedSize;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:42:25 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 13:03:03 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
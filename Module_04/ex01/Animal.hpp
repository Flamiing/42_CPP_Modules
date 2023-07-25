/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:39:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/25 11:08:45 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& other);
		virtual ~Animal(void);

		Animal& operator=(const Animal& other);

		virtual void makeSound(void) const;
		std::string getType(void) const;
	protected:
		std::string _type;
};

#endif
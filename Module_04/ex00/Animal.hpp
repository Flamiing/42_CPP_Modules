/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:39:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/22 19:17:49 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		~Animal(void);

		Animal& operator=(const Animal& other);

		void	makeSound(void);
	protected:
		std::string _type;
};

#endif
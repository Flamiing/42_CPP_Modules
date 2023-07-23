/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:17 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 16:39:29 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& other);
		~Dog(void);

		Dog& operator=(const Dog& other);

		void makeSound(void) const;
		void changeIdea(int index, const std::string idea);
		std::string thinkIdea(int index) const;
	private:
		Brain* _brain;
};

#endif
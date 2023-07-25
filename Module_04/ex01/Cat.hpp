/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:13 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/25 11:08:57 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		virtual ~Cat(void);

		Cat& operator=(const Cat& other);

		void makeSound(void) const;
		void changeIdea(int index, const std::string idea);
		std::string thinkIdea(int index) const;
	private:
		Brain* _brain;
};

#endif
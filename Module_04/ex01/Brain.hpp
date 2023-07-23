/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:20:28 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 16:30:47 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);
		
		Brain& operator=(const Brain& other);

		void setIdea(int index, const std::string idea);
		std::string getIdea(int index) const;
	private:
		std::string _ideas[100];
};

#endif
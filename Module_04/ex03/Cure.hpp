/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:31:47 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/26 18:53:10 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "info.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& other);
		virtual ~Cure(void);
		
		Cure& operator=(const Cure& other);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
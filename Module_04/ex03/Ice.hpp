/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:31:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/26 18:53:13 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "info.hpp"
# include <iostream>

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& other);
		virtual ~Ice(void);
		
		Ice& operator=(const Ice& other);
		
		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
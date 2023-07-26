/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:01:30 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/26 18:52:39 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include "info.hpp"
# include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(const std::string type);
		AMateria(const AMateria& other);
		virtual ~AMateria(void);
		
		AMateria& operator=(const AMateria& other);

		std::string const& getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string _type;
};

#endif
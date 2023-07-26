/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:42:31 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/26 18:53:26 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "info.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource(void);
		
		MateriaSource& operator=(const MateriaSource& other);

		virtual void learnMateria(AMateria* learn);
		virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria* _learned[4];
};

#endif
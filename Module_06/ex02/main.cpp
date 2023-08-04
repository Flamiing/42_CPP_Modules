/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 03:24:21 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 13:00:50 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realType.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base* randomClass1 = generate();
	Base* randomClass2 = generate();
	Base* randomClass3 = generate();

	identify(randomClass1);
	identify(randomClass2);
	identify(randomClass3);

	identify(*randomClass1);
	identify(*randomClass2);
	identify(*randomClass3);

	delete randomClass1;
	delete randomClass2;
	delete randomClass3;
	return 0;
}
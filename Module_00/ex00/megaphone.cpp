/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:14:38 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/19 19:10:48 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	count;
	int	pos;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::std::endl;
	else
	{
		count = 1;
		while (count < argc)
		{
			pos = 0;
			while (pos < (int)strlen(argv[count]))
			{
				std::cout << (char)toupper(argv[count][pos]);
				pos++;
			}
			count++;
		}
		std::cout << std::std::endl;
	}
	return (0);
}

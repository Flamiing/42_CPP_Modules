/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:14:38 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 02:01:16 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	size_t	pos;
	int	count;
	std::string	word;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	count = 1;
	while (argc > 1 && count < argc)
	{
		pos = 0;
		word = std::string(argv[count]);
		while (pos < word.length())
		{
			std::cout << char(std::toupper(word[pos]));
			pos++;
		}
		count++;
	}
	std::cout << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_capitalizer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:45:13 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:45:15 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	nb;

	nb = argc - 1;
	if (argc > 1)
	{
		j = 1;
		while (nb--)
		{
			i = 1;
			if (argv[j][0] <= 'z' && argv[j][0] >= 'a')
				argv[j][0] -= 32;
			write(1, &argv[j][0], 1);
			while (argv[j][i])
			{
				if (argv[j][i] == ' ' || argv[j][i] == '\t')
				{
					write(1, &argv[j][i], 1);
					if (argv[j][i + 1] && argv[j][i + 1] <= 'z' && argv[j][i
						+ 1] >= 'a')
					{
						argv[j][i + 1] -= 32;
						write(1, &argv[j][i + 1], 1);
						i++;
					}
					else if (argv[j][i + 1] && argv[j][i + 1] <= 'Z'
						&& argv[j][i + 1] >= 'A')
					{
						write(1, &argv[j][i + 1], 1);
						i++;
					}
					i++;
				}
				while (argv[j][i] != ' ' && argv[j][i] != '\t' && argv[j][i])
				{
					if (argv[j][i] <= 'Z' && argv[j][i] >= 'A')
						argv[j][i] += 32;
					write(1, &argv[j][i], 1);
					i++;
				}
			}
			j++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

// Assignment name  : str_capitalizer
// Expected files   : str_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or several strings and, for each argument,
// capitalizes the first character of each word (If it's a letter, obviously),
// puts the rest in lowercase, and displays the result on the standard output,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string. If a word only has one letter, it must be
// capitalized.

// If there are no arguments, the progam must display \n.

// Example:

// $> ./str_capitalizer | cat -e
// $
// $> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
// A First Little Test$
// $> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay,
	this is the last 1239809147801 but not    the least    t" | cat -e
// __second Test A Little Bit   Moar Complex$
//    But... This Is Not That Complex$
//      Okay, This Is The Last 1239809147801 But Not    The Least    T$
// $>

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wdmatch.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:49:25 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:59:38 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	char	*str1;
	char	*str2;
	int		len1;
	int		len2;
	int		i;
	int		j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	str1 = argv[1];
	str2 = argv[2];
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	i = 0;
	j = 0;
	while (i < len1 && j < len2)
	{
		if (str1[i] == str2[j])
			i++;
		j++;
	}
	if (i == len1)
	{
		i = 0;
		while (str1[i])
		{
			write(1, &str1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : wdmatch
// Expected files   : wdmatch.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and checks whether it's possible to
// write the first string with characters from the second string,
// while respecting
// the order in which these characters appear in the second string.

// If it's possible, the program displays the string, followed by a \n,
// otherwise
// it simply displays a \n.

// If the number of arguments is not 2, the program displays a \n.

// Examples:

// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat
// -e
// forty two$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $
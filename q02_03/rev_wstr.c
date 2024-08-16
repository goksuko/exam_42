/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_wstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:48:14 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:48:16 by akaya-oz      ########   odam.nl         */
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
	int		i;
	int		start;
	char	*str;
	int		len;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	len = ft_strlen(str);
	if (len == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = len - 1;
	while (i--)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			start = i + 1;
			while (str[start] != ' ' && str[start] != '\t' && start < len)
			{
				write(1, &str[start], 1);
				start++;
			}
			write(1, " ", 1);
		}
	}
	start = 0;
	while (str[start] != ' ' && str[start] != '\t' && start < len)
	{
		write(1, &str[start], 1);
		start++;
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the
// begin/end of the string.

// If the number of parameters is different from 1, the program will display
// '\n'.

// In the parameters that are going to be tested,
// there will not be any "additional"
// spaces (meaning that there will not be additionnal spaces at the beginning or at
// the end of the string,
// and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat
// -e
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

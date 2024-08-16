/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:43:07 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:43:09 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (i >= j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j++;
		i--;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "Hello";

	printf("%s\n", ft_strrev(str));
	return (0);
}

// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);
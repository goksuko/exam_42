/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:43:20 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:43:22 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1 && s2)
		i++;
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	char *str1 = "Adana";
// 	char *str2 = "Ankara";

// 	printf("my: %d\n", ft_strcmp(str1, str2));
// 	printf("org: %d\n", strcmp(str1, str2));
// 	return (0);
// }

// Assignment name  : ft_strcmp
// Expected files   : ft_strcmp.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcmp (man strcmp).

// Your function must be declared as follows:

// int    ft_strcmp(char *s1, char *s2);
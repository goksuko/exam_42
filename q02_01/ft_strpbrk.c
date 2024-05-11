/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strpbrk.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:43:11 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:43:12 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	j = 0;
	while (s2[j])
	{
		i = 0;
		while (s1[i])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			i++;
		}
		j++;
	}
	return (NULL);
}

int	main(void)
{
	char	s1[] = "Hello World";
	char	s2[] = "alo";

	printf("org: %s\n", strpbrk(s1, s2));
	printf(" my: %s\n", ft_strpbrk(s1, s2));
	return (0);
}

// Assignment name : ft_strpbrk
// Expected files : ft_strpbrk.c
// Allowed functions : None--
// -------------------------------------------------------------
// Reproduce exactly the behavior of the function
// strpbrk(man strpbrk)
// 													.
// The function should be prototyped as follows :

// 	char *ft_strpbrk(const char *s1, const char *s2);
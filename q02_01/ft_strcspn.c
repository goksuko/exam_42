/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcspn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:43:17 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:43:19 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (reject[k])
		{
			if (s[i] == reject[k])
				return (i);
			k++;
		}
		i++;
		k = 0;
	}
	return (i);
}

// int	main(void)
// {
// 	char *str1 = "Adanaya";
// 	// char *str2 = "aya";
// 	// char	*str2 = "ne";
// 	char	*str2 = "f";
// 	// char	*str2 = "en";

// 	printf("my: %ld\n", ft_strcspn(str1, str2));
// 	printf("org: %ld\n", strcspn(str1, str2));
// 	return (0);
// }

// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);
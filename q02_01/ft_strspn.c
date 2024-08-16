/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strspn.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:43:04 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:43:06 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				break ;
			j++;
		}
		if (!accept[j])
			break ;
		i++;
	}
	return (i);
}

int	main(void)
{
	char	s[] = "Hello World";
	char	accept[] = "Helo ";

	printf("org: %lu\n", strspn(s, accept));
	printf(" my: %lu\n", ft_strspn(s, accept));
	return (0);
}

// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);
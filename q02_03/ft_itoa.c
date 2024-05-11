/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:47:19 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:47:20 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int nbr)
{
	char	*str;
	int		sign;
	int		count;
	int		i;
	int		copy;

	sign = 1;
	count = 1;
	if (nbr < 0)
	{
		sign = -1;
		nbr = -1 * nbr;
		count++;
	}
	copy = nbr;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		count++;
	}
	nbr = copy;
	str = malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	i = count;
	i--;
	while (nbr >= 10)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	str[i] = (nbr % 10) + '0';
	str[count] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char *s;

// 	s = ft_itoa(-10);
// 	printf("%s\n", s);
// 	free(s);
// 	s = NULL;
// 	return (0);
// }

// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_power_of_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:42:58 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:42:59 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 2 || n == 1)
		return (1);
	while (n % 2 == 0 && n > 2)
	{
		n = n / 2;
		if (n == 2)
			return (1);
		else if (n < 2)
			return (0);
	}
	return (0);
}

// int main(void)
// {
// 	int i;

// 	i = is_power_of_2(128);
// 	printf("%d\n", i);
// 	return (0);
// }

// Assignment name  : is_power_of_2
// Expected files   : is_power_of_2.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that determines if a given number is a power of 2.

// This function returns 1 if the given number is a power of 2, otherwise it returns 0.

// Your function must be declared as follows:

// int	    is_power_of_2(unsigned int n);

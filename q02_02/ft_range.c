/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_range.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:44:44 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:44:46 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	total;
	int	*array;
	int	i;

	total = end - start;
	if (total < 0)
		total *= -1;
	total += 1;
	array = malloc(sizeof(int) * total);
	if (!array)
		return (NULL);
	i = 0;
	total = end - start;
	if (total < 0)
	{
		total *= -1;
		total += 1;
		while (i < total)
		{
			array[i] = start;
			i++;
			start--;
		}
	}
	else
	{
		total += 1;
		while (i < total)
		{
			array[i] = start;
			i++;
			start++;
		}
	}
	return (array);
}

// int main()
// {
// 	int *array = ft_range(0, -3);
// 	int i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("array[%d] = %d\n", i, array[i]);
// 		i++;
// 	}
// 	return (0);
// }

// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers,
	fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

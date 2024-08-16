/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rrange.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:44:48 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:44:50 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// nicer
// int		absolute_value(int n);

// int		*ft_rrange(int start, int end)
// {
// 	int number_of_ints;
// 	int *array;
// 	int step;
// 	int i;

// 	number_of_ints = 1 + absolute_value(end - start);
// 	array = malloc(sizeof(int) * number_of_ints);

// 	if (start > end)
// 		step = 1;
// 	else
// 		step = -1;

// 	i = 0;
// 	while (i < number_of_ints)
// 	{
// 		array[i] = end;
// 		end = end + step;
// 		++i;
// 	}
// 	return (array);
// }

int	*ft_rrange(int start, int end)
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
			array[i] = end;
			i++;
			end++;
		}
	}
	else
	{
		total += 1;
		while (i < total)
		{
			array[i] = end;
			i++;
			end--;
		}
	}
	return (array);
}

// int main()
// {
// 	int *array = ft_rrange(0, 3);
// 	int i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("array[%d] = %d\n", i, array[i]);
// 		i++;
// 	}
// 	return (0);
// }

// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers,
	fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

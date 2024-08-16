/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lcm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:44:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:44:56 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

unsigned int	lcm2(unsigned int a, unsigned int b)
{
	unsigned int	n;

	n = 1;
	while (1)
	{
		if (a * n % b == 0)
			return (a * n);
		n++;
	}
}

unsigned int	lcm3(unsigned int a, unsigned int b)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	result;

	i = 2;
	result = 1;
	j = 0;
	if (a <= 0 || b <= 0)
		return (0);
	if (a == 1)
		return (b);
	if (b == 1)
		return (a);
	while (a >= i && b >= i)
	{
		if (j != 0)
			i = j;
		if (a % i == 0 || b % i == 0)
		{
			j = i;
			if (a % i == 0)
				a = a / i;
			if (b % i == 0)
				b = b / i;
			result = result * i;
		}
		else
			j = 0;
		i++;
	}
	if (a != 1)
		result = result * a;
	if (b != 1)
		result = result * b;
	return (result);
}

// int main()
// {
// 	printf("%d\n", lcm(15, 30));
// 	printf("%d\n", lcm(15, 31));
// 	printf("%d\n", lcm(15, 32));
// 	printf("%d\n", lcm(15, 33));
// 	printf("%d\n", lcm2(15, 30));
// 	printf("%d\n", lcm2(15, 31));
// 	printf("%d\n", lcm2(15, 32));
// 	printf("%d\n", lcm2(15, 33));
// 	printf("%d\n", lcm3(15, 30));
// 	printf("%d\n", lcm3(15, 31));
// 	printf("%d\n", lcm3(15, 32));
// 	printf("%d\n", lcm3(15, 33));
// 	return (0);
// }

// Assignment name  : lcm
// Expected files   : lcm.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function who takes two unsigned int as parameters and returns the
// computed LCM of those parameters.

// LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
// integer divisible by the both integers.

// A LCM can be calculated in two ways:

// - You can calculate every multiples of each integers until you have a common
// multiple other than 0

// - You can use the HCF (Highest Common Factor) of these two integers and
// calculate as follows:

// 	LCM(x, y) = | x * y | / HCF(x, y)

//   | x * y | means "Absolute value of the product of x by y"

// If at least one integer is null, LCM is equal to 0.

// Your function must be prototyped as follows:

//   unsigned int    lcm(unsigned int a, unsigned int b);

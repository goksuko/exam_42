/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paramsum.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:44:58 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:44:59 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = nb % 16 + '0';
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	nb;

	(void)argv; // Silence 'unused parameter' error
	nb = argc - 1;
	ft_putnbr(nb);
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it,
	followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:45:05 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/09/13 12:34:27 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int my_atoi(char *str)
{
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb *10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

void my_hex(int nb)
{
	char *str = "0123456789abcdef";

	if (nb >= 16)
	{
		my_hex(nb / 16);
	}
	write(1, &str[nb % 16], 1);
}



int main()
{
	printf("%d\n", my_atoi("-2452345"));
	printf("%d\n", my_atoi("2452345"));
	my_hex(5156454);
	return (0);
}






int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		nb = 10 * nb + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_putnbr_hex(int nb)
{
	char	*array;
	int		c;

	array = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16);
	}
	c = nb % 16;
	write(1, &array[c], 1);
}

// int	main(int argc, char *argv[])
// {
// 	int	nb;

// 	if (argc == 2)
// 	{
// 		nb = ft_atoi(argv[1]);
// 		ft_putnbr_hex(nb);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

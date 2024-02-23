
#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		nb = 10 * nb + (str[i] - '0');
		i++;
	}
	return (nb);
}

int	main (int argc, char *argv[])
{
	int	nb1;
	int nb2;
	int i;

	if (argc == 3)
	{
		nb1 = ft_atoi(argv[1]);
		nb2 = ft_atoi(argv[2]);
		i = nb1;
		while (i--)
		{
			if (nb1 % i == 0 && nb2 % i == 0)
				break;
		}
		printf("%d", i);
	}
	printf ("\n");
	return (0);
}

// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e 
// 1$
// $> ./pgcd | cat -e
// $

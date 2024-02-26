#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int	count_word_nb(char *str)
{
	int	i;
	int	s;
	
	i = 0;
	s = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		{
			i++;
			s++;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
				i++;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (s);
}

void fill_matrix(char *str, char **matrix)
{
	int	i;
	int j;
	int k;
	int t;

	i = 0;
	j = 0;
	k = 0;
	t = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
			j++;
		}
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			i++;
			k++;
		}
		matrix[t] = malloc(sizeof(char) * k + 1);
		if (matrix[t] == NULL)
			return ;
		matrix[t][k] = '\0';
		k = 0;
		while (str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && str[i])
		{
			// printf("loop i: %d, j: %d, k: %d, t: %d\n", i, j, k, t);
			matrix[t][k] = str[j];
			// printf("matrix[%d][%d] (%c) = str[%d] (%c)\n", t, k, matrix[t][k], j, str[j]);
			j++;
			k++;
		}
		matrix[t][k] = '\0';
		k = 0;
		t++;
	}
}

static char    **ft_split(char *str)
{
	char **matrix;
	int	s;

	s = count_word_nb(str);
	matrix = malloc(sizeof(char) * s + 1);
	if (matrix == NULL)
		return (NULL);
	matrix[s] = '\0';
	fill_matrix(str, matrix);
	return(matrix);
}

void print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char **matrix;
	int i;

	if (argc >= 2)
	{
		i = 1;
		printf("test\n");
		matrix = ft_split(argv[1]);
		printf("test\n");
		while (*matrix[i] != '\0')
		{
			printf("--test\n");
			print_str(matrix[i]);
			write (1, " ", 1);
			i++;
		}
		printf("test\n");
		print_str(matrix[0]);
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
	return (0);
}

// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>

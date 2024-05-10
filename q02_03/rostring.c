#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		start;
	char	*str;
	int		len;
	int		end;
	int		more_than_one_word;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	len = ft_strlen(str);
	if (len == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	more_than_one_word = 0;
	i = len - 1;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	end = i;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && i <= end)
	{
		more_than_one_word = 1;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && i <= end)
			write(1, &str[i++], 1);
		if (i <= end)
			write(1, " ", 1);
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	if (more_than_one_word == 1)
		write(1, " ", 1);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t' && i < len)
		write(1, &str[i++], 1);
	write(1, "\n", 1);
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

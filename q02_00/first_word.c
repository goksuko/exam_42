/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_word.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:45:40 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:45:43 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*org;
	int		i;

	org = argv[1];
	if (argc == 2)
	{
		i = 0;
		if (org[i] != '\0')
		{
			while (org[i] != '\0' && (org[i] == ' ' || org[i] == '\t'))
				i++;
			while (org[i] != '\0' && org[i] != ' ' && org[i] != '\t')
			{
				write(1, &org[i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : first_word
// Expected files   : first_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its first word,
	followed by a
// newline.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or if there are no words,
	simply display
// a newline.

// Examples:

// $> ./first_word "FOR PONY" | cat -e
// FOR$
// $> ./first_word "this        ...       is sparta, then again,
	maybe    not" | cat -e
// this$
// $> ./first_word "   " | cat -e
// $
// $> ./first_word "a" "b" | cat -e
// $
// $> ./first_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

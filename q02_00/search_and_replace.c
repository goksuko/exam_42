/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_and_replace.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:46:31 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:46:33 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*str;
	char	org;
	char	rep;

	if (argc == 4)
	{
		i = 0;
		str = argv[1];
		org = argv[2][0];
		rep = argv[3][0];
		if (argv[2][1] != '\0' || argv[3][1] != '\0')
			str[0] = '\0';
		while (str[i])
		{
			if (str[i] == org)
				str[i] = rep;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : search_and_replace
// Expected files   : search_and_replace.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program called search_and_replace that takes 3 arguments, the first
// arguments is a string in which to replace a letter (2nd argument) by
// another one (3rd argument).

// If the number of arguments is not 3, just display a newline.

// If the second argument is not contained in the first one (the string)
// then the program simply rewrites the string followed by a newline.

// Examples:
// $>./search_and_replace "Papache est un sabre" "a" "o"
// Popoche est un sobre
// $>./search_and_replace "zaz" "art" "zul" | cat -e
// $
// $>./search_and_replace "zaz" "r" "u" | cat -e
// zaz$
// $>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
// $
// $>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
// ZaZ eT David aiME le METal.$
// $>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat
	-e
// eNcOre Un ExEmPle Pas Facile a Ecrire $

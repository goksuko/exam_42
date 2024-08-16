/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alpha_mirror.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:38:41 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:38:52 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*str;

	i = 0;
	if (argc == 2)
	{
		str = argv[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = 'a' + 'z' - str[i];
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = 'A' + 'Z' - str[i];
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : alpha_mirror
// Expected files   : alpha_mirror.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called alpha_mirror that takes a string and displays this string
// after replacing each alphabetical character by the opposite alphabetical
// character, followed by a newline.

// 'a' becomes 'z', 'Z' becomes 'A'
// 'd' becomes 'w', 'M' becomes 'N'

// and so on.

// Case is not changed.

// If the number of arguments is not 1, display only a newline.

// Examples:

// $>./alpha_mirror "abc"
// zyx
// $>./alpha_mirror "My horse is Amazing." | cat -e
// Nb slihv rh Znzarmt.$
// $>./alpha_mirror | cat -e
// $
// $>

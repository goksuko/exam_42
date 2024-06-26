/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_to_be_studied.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:47:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:47:25 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\0')
		{
			i++;
			s++;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
				&& str[i] != '\0')
				i++;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (s);
}

void	fill_matrix(char *str, char **matrix)
{
	int	i;
	int	j;
	int	k;
	int	t;

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
		matrix[t] = malloc(sizeof(char) * k);
		if (matrix[t] == NULL)
			return ;
		matrix[t][k] = '\0';
		k = 0;
		while (str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && str[j])
		{
			printf("loop i: %d, j: %d, k: %d, t: %d\n", i, j, k, t);
			matrix[t][k] = str[j];
			printf("matrix[%d][%d] (%c) = str[%d] (%c)\n", t, k, matrix[t][k],
				j, str[j]);
			j++;
			k++;
		}
		printf("matrix[%d][%d] (%c) = null character \n", t, k, matrix[t][k]);
		k = 0;
		t++;
	}
}

static char	**ft_split(char *str)
{
	char	**matrix;
	int		s;

	s = count_word_nb(str);
	printf("s: %d\n", s);
	matrix = malloc(sizeof(char) * s + 1);
	if (matrix == NULL)
		return (NULL);
	matrix[s] = NULL;
	printf("matrix[s]: %s\n", matrix[s]);
	fill_matrix(str, matrix);
	return (matrix);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

int	main(void)
{
	char	**matrix;
	char	*str;
	int		i;

	// str = "  life is beautiful!	and sometimes 	hard!   ";
	str = "life";
	i = 0;
	matrix = ft_split(str);
	printf("org: \"%s\"\n", str);
	printf("matrix[1][0]: \"%c\"\n", matrix[1][0]);
	while (*matrix[i])
	{
		printf("matrix[%d] = %s\n", i, matrix[i]);
		i++;
	}
	// free_matrix(matrix);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	char	**split;
// 	int		i;

// 	if (argc == 2)
// 	{
// 		split = ft_split(argv[1]);
// 			printf("%s ", split[0]);
// 		i = 1;
// 		while (split[i] != 0)
// 		{
// 			printf("%s ", split[i]);
// 			i++;
// 		}
// 		printf("%s", split[i]);
// 	}
// 	printf("\n");
//     return (0);
// }

// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words,
	and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);
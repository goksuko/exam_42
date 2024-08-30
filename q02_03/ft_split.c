/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 10:48:14 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/11/13 16:51:04 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/

#include "libft.h"

//from Diane

char		**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 256)))
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i += 1;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			split[k][j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i += 1;
		split[k][j] = '\0';
		k += 1;
	}
	split[k] = NULL;
	return (split);
}

int main (int argc, char *argv[])
{
	int		i;
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1]);
		i = 0;
		while (split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
	return (0);
}

/*
static char	**clean(char **matrix, size_t string_no)
{
	while (string_no--)
		free(matrix[string_no]);
	free(matrix);
	return (NULL);
}

static int	count_strings(const char *s, char delimiter)
{
	size_t	string_nb;

	string_nb = 0;
	while (*s)
	{
		while (*s == delimiter && *s)
			s++;
		if (*s != delimiter && *s)
		{
			string_nb++;
			while (*s != delimiter && *s)
				s++;
		}
	}
	return (string_nb);
}

static char	**fill_matrix(char **matrix, const char *s, char c)
{
	size_t	i;
	size_t	string_no;
	size_t	string_len;
	size_t	start;

	i = 0;
	string_no = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			string_len = i - start;
			matrix[string_no] = ft_substr(s, start, string_len);
			if (matrix[string_no] == NULL)
				return (clean(matrix, string_no));
			string_no++;
		}
	}
	matrix[string_no] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	int		string_nb;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	string_nb = count_strings(s, c);
	matrix = (char **)malloc(sizeof(char *) * (string_nb + 1));
	if (matrix == NULL)
		return (NULL);
	matrix = fill_matrix(matrix, s, c);
	if (matrix == NULL)
		return (NULL);
	matrix[string_nb] = NULL;
	return (matrix);
}

int main(void)
{
	int i;
	char str[] = "hello!";
	char c = ' ';
	char **matrix = ft_split(str, c);

	i = 0;
	while(matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}
*/
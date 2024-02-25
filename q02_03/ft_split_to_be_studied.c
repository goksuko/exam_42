#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_word_nb(char *str)
{
	int	i;
	int	s;
	
	i = 0;
	s = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			i++;
		}
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
			s++;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
	}
	i--;
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		s--;
	return (s + 1);
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
		k = 0;
		while (str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && str[i])
		{
			printf("loop i: %d, j: %d, k: %d, t: %d\n", i, j, k, t);
			matrix[t][k] = str[j];
			printf("matrix[%d][%d] = str[%d]\n", t, k, j);
			j++;
			k++;
		}
		matrix[t][k] = '\0';
		k = 0;
		t++;
	}
}

char    **ft_split(char *str)
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

int main()
{
	char **matrix;
	char *str;
	int	i;

	str = "		 life is beautiful!	and sometimes 	hard!   ";
	i = 0;
	matrix = ft_split(str);
	printf("org: \"%s\"\n", str);
	while (*matrix[i])
	{
		printf("matrix[%d] = %s\n", i, matrix[i]);
		i++;
	}
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

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);
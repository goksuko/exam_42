#include <stdio.h>
#include <stdlib.h>

char		**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	split = (char **)malloc(sizeof(char *) * 256);
    if (!split)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i += 1;
	while (str[i])
	{
		j = 0;
		split[k] = (char *)malloc(sizeof(char) * 4096);
        if (!split[k])
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

int main(void)
{
	int i;
	char str[] = "hello sweethart! hoe gaat het?";
	char c = ' ';
	char **matrix = ft_split(str);

	i = 0;
	while(matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

// int main (int argc, char *argv[])
// {
// 	int		i;
// 	char	**split;

// 	if (argc == 2)
// 	{
// 		split = ft_split(argv[1]);
// 		i = 0;
// 		while (split[i])
// 		{
// 			printf("%s\n", split[i]);
// 			i++;
// 		}
// 	}
// 	return (0);
// }
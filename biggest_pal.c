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

void	now_write(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_strcpy_from(char *dest, char *src, int j)
{
	int	i;

	i = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*find_longest_of(char **pals, int len)
{
	int	index;
	int	max_len;
	int	length;
	int	result;

	index = 0;
	max_len = 0;
	result = 0;
	while (index < len)
	{
		if (!pals[index])
			length = 0;
		else
			length = ft_strlen(pals[index]);
		if (length >= max_len)
		{
			max_len = length;
			result = index;
		}
		index++;
	}
	return (pals[result]);
}

char	*ft_strcpy_till(char *dest, const char *src, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*find_longest_from(char *str)
{
	char	*temp;
	int		i;
	int		j;
	int		end;

	j = ft_strlen(str) - 1;
	i = 0;
	while (str && str[i])
	{
		i = 0;
		end = j;
		while (str[i] == str[j] && j > i)
		{
			j--;
			i++;
		}
		if (i >= j)
		{
			temp = malloc(sizeof(char) * (j - i) + 1);
			if (!temp)
				return (0);
			temp = ft_strcpy_till(temp, str, end);
			return (temp);
		}
		else
			j = end - 1;
	}
	return (NULL);
}

char	**find_palindromes(char **strings, int len)
{
	char	**pals;
	int		index;
	int		size;
	char	*temp;
	int		length;

	pals = malloc(sizeof(char *) * len + 1);
	if (!pals)
		return (0);
	pals[len] = '\0';
	index = 0;
	size = len;
	while (index < len)
	{
		temp = find_longest_from(strings[index]);
		length = ft_strlen(temp);
		if (length > 0)
		{
			pals[index] = malloc(sizeof(char) * length + 1);
			if (!pals[index])
				return (0);
			pals[index][length] = '\0';
			pals[index] = ft_strcpy_from(pals[index], temp, 0);
		}
		index++;
		size--;
	}
	return (pals);
}

char	**create_copy_strings(char *str, int len)
{
	char	**strings;
	int		i;
	int		size;

	strings = malloc(sizeof(char *) * len + 1);
	if (!strings)
		return (0);
	strings[len] = '\0';
	i = 0;
	size = len;
	while (i < len)
	{
		strings[i] = malloc(sizeof(char) * size + 1);
		if (!strings[i])
			return (0);
		strings[i][size] = '\0';
		strings[i] = ft_strcpy_from(strings[i], str, i);
		strings[i][size] = '\0';
		i++;
		size--;
	}
	return (strings);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		len;
	char	**pals;
	char	**strings;
	char	*longest;

	str = argv[1];
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = ft_strlen(str);
	strings = create_copy_strings(str, len);
	pals = find_palindromes(strings, len);
	if (!pals)
	{
		write(1, "\n", 1);
		return (0);
	}
	longest = find_longest_of(pals, len);
	now_write(longest);
	return (0);
}

// Assignment name  : biggest_pal
// Expected files   : *.c, *.h
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program named biggest_pal that takes a string as argument and prints the
// biggest palindrome included inside this string, followed by a newline.

// This string contains only lowercase characters.

// If there is two palindromes of the same length,
// you have to print the last one.

// If there is more or less than 1 argument,
// your program must print only a newline
// only.

// Exemples:

// $> biggest_pal "abcba"
// abcba
// $> biggest_pal "aaaaaaaaaabbcbbaaaa"
// aaaabbcbbaaaa
// $> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
// zeldaisaboyobasiadlez
// $> biggest_pal "aeibaabaammaabaalek"
// aabaammaabaa
// $> biggest_pal abeb qpinqwjobo qkmnwoiq

// $> biggest_pal

// $>
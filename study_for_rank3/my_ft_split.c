#include <stdio.h>
#include <stdlib.h>

char **my_ft_split(char *str, char c)
{
    int i;
    int j;
    int k;
    char **matrix;

    if (str == NULL)
        return (NULL);
    matrix = (char **)malloc(sizeof(char *) * 256);
    if (!matrix)
        return (NULL);
    i = 0;
    k = 0;
    while (str[i] == c)
        i++;
    while (str[i])
    {
        matrix[k] = (char *)malloc(sizeof(char) * 4000);
        if (!matrix[k])
            return (NULL);        j = 0;
        while (str[i] && str[i] != c)
        {
            matrix[k][j] = str[i];
            i++;
            j++;
        }
        while (str[i] == c)
            i++;
        matrix[k][j] = '\0';
        k++;
    }
    matrix[k] = NULL;
    return (matrix);
}

int main()
{
    
    char **matrix;
    char *str;
    char c;
    int i;

    str = "   Hello world! It is rainy today     !!!  ";
    c = ' ';
    matrix = my_ft_split(str, c);
    if (!matrix)
        return(1);
    i = 0;
    while (matrix[i])
    {
        printf("%s\n", matrix[i]);
        i++;
    }
    return (0);
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int argc, char *argv[])
{
    int i;
    char **storage;
    char **other;
    int s;
    int o;
    int j;
    char *str;
    int len;
    int pass;
    char *temp;

    i = 0;
    s = 0;
    j = 0;
    o = 0;
    pass = 0;
    if (argc == 1)
        return (1);
    str = argv[1];
    storage = malloc(sizeof(char *) * 100);
    other = malloc(sizeof(char *) * 100);

    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] != '/')
        {
            j = i + 1;
            len = 0;
            while (str[j] != '>' && str[j] != ' ')
            {
                j++;
                len++;
            }
            if (str[j] == ' ')
                pass = 1;
            if (pass == 1)
            {
                o++;
                other[o] = malloc(sizeof(char) * len + 1);
                strncpy(other[o], &str[i + 1], len);
            }
            else
            {
                s++;
                storage[s] = malloc(sizeof(char) * len + 1);
                strncpy(storage[s], &str[i + 1], len);
            }
            pass = 0;
        }
        else if (str[i] == '<' && str[i + 1] == '/')
        {
            j = i + 2;
            len = 0;
            while (str[j] != '>')
            {
                j++;
                len++;
            }
            temp = malloc(sizeof(char) * len + 1);
            strncpy(temp, &str[i + 2], len);
            if (other[o] && strncmp(other[o], temp, len) == 0)
            {
                free(other[o]);
                o--;
            }
            else if (storage[s] && strncmp(storage[s], temp, len) == 0)
            {
                free(storage[s]);
                s--;
            }
            else
                return (1);
        }
        i++;
    }
    if (s == 0)
        return (0);
    else
        return (1);
}



// Assignment name  : html_validator
// Expected files   : *.c
// Allowed functions: write, malloc, strncmp, strncpy, free
// --------------------------------------------------------------------------------

// Write a program that takes a strings as argument and checks the html tags. 
// You don't need to know html to do this assignment.
// Your program must return a 0 for valid input and prints on the standard output "OK" followed by a newline
// if the expression is correctly bracketed, otherwise it returns 1 and prints "KO" followed by
// a newline.

// HTML opening tags look like this:
// <something> and closing tags like this </something>

// An opening tag must always be closed by the good closing tag in the
// correct order. 

// If there is no arguments, the program must print only a newline.

// Examples :

// $> ./html_validator '<b><blue></blue></b>'; echo$?
// 0

// $> ./html_validator '<b><blue></b></blue>'; echo$?
// 1

// $> ./html_validator '<blue attribute="bladiebla"></blue>'; echo$?
// 0

// $> ./html_validator '<img bladiebla><blue></blue>'; echo$?
// 0


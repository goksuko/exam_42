#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

bool check_brackets(char *str)
{
    int i;
    char storage[100][100];
    int s;
    int j;

    i = 0;
    s = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] != '/')
        {
            s++;
            i++;
            while (str[i] != '>')
            {
               storage[s][j] = str[i];
               i++;
               j++;
            }
            storage[s][j] = '\0';
            j = 0;
        }
        else if (str[i] == '<' && str[i + 1] == '/')
        {
            i++;
            i++;
            while (str[i] != '>')
            {
               if (storage[s][j] != str[i])
                    return (false);
               i++;
               j++;
            }
            j = 0;
            s--;
        }
        i++;
    }
    return (true);
}

int main(int argc, char *argv[])
{
    int i;
    bool result;

    if (argc == 1)
        write(1, "\n", 1);
    i = 1;
    while (argv[i])
    {
        result = check_brackets(argv[i]);
        if (result == true)
        {
            write(1, "OK\n", 3);
            return (0);
        }
        else
        {
            write(1, "KO\n", 3);
            return (1);
        }
        i++;
    }
}



// Assignment name  : html_validator
// Expected files   : *.c
// Allowed functions: write
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

// $> ./html_validator '<b><blue></blue></b>'
// OK

// $> ./html_validator '<b><blue></b></blue>'
// KO$

// 2 extra challanges:
// - Tags can contain attributes, like this:
// <blue attribute="bladiebla"> and closing </blue>
// - IMG tags can exist on their own and don't need to be closed:
// <img blue bla>
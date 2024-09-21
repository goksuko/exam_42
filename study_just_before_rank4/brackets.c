#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>


char matching(char opening)
{
    char closing;

    closing = ' ';
    if (opening == ')')
        closing = '(';
    else if (opening == '}')
        closing = '{';
    else if (opening == ']')
        closing = '[';
    return (closing);
}

bool check_brackets(char *str)
{
    int i;
    int storage[1000];
    int s;

    i = 0;
    s = 0;
    while (str[i])
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s++;
            storage[s] = str[i];

        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            // printf("%c\n", str[i]);
            // printf("%c\n", storage[s]);
            // printf("%c\n", matching(str[i]));
            if (storage[s] != matching(str[i]))
                return (false);
            else
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
            write(1, "OK", 2);
        else
            write(1, "Error", 5);
        write(1, "\n", 1);
        i++;
    }
}






// Assignment name  : brackets
// Expected files   : *.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes an undefined number of strings in arguments. For each
// argument, the program prints on the standard output "OK" followed by a newline
// if the expression is correctly bracketed, otherwise it prints "Error" followed by
// a newline.

// Symbols considered as 'brackets' are brackets '(' and ')', square brackets '['
// and ']'and braces '{' and '}'. Every other symbols are simply ignored.

// An opening bracket must always be closed by the good closing bracket in the
// correct order. A string which not contains any bracket is considered as a
// correctly bracketed string.

// If there is no arguments, the program must print only a newline.

// Examples :

// $> ./brackets '(johndoe)' | cat -e
// OK$
// $> ./brackets '([)]' | cat -e
// Error$
// $> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
// OK$
// OK$
// $> ./brackets | cat -e
// $
// $>



// HTML variant:
// Waar je html tags moet checken.
// Of elk opening tag ook daadwerkelijk
// goed gesloten wordt met eenzelfde closing tag.
// Zoals dit:
// <b><blue></blue></b> = OK
// <b><blue></b></blue> = Error

// 2 extra uitdagingen:
// - Tags kunnen er ook zo uit zien:
// <blue attribute="bladiebla"> 
// - IMG tags hoeven niet gesloten te worden!
// <img blue bla>
#include <stdbool.h> // for bool
#include <unistd.h> // for write

bool matches(char first, char second)
{
	if ((first == '(' && second == ')')
		|| (first == '[' && second == ']')
		|| (first == '{' && second == '}'))
		return (true);
	return (false);
}

bool	check_parenthesis(char *str)
{
	int	i = 0;
	int	stack_size = 0;
	int	stack[1024];

	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') // if opening bracket
		{
            stack_size++; // increment stack size
			stack[stack_size] = str[i]; // push opening bracket to stack
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') // if closing bracket
		{
			if (matches(stack[stack_size], str[i]) == false) // check if closing bracket matches opening bracket
				return (false);
			stack_size--; // if so: fake pop opening bracket from stack
		}
		i++;
	}
    if (stack_size == 0) // validate stack is empty -> only matching pairs found
	    return (true);
    return (false);
}

int main(int argc, char **argv)
{
	
	int i;
	
	i = 1;
	if (argc == 1)
		return (write(1, "\n", 1));
	while (i < argc)
	{
		if (check_parenthesis(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
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
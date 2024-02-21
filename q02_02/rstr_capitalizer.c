#include <unistd.h>

int main(int argc, char *argv[])
{
	char *str;
	int i;
	int j;
	
	j = 1;
	if (argc >= 2)
	{
		while (j < argc)
		{
			str = argv[j];
			i = 0;
			while (str[i] != '\0')
			{
				while (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0' )
				{
					if (str[i] >= 'A' && str[i] <= 'Z' )
						str[i] = str[i] + 32;
					write(1, &str[i], 1);
					i++;
				}
				if (str[i + 1] == ' ' || str[i + 1] == '\t')
				{
					if (str[i] >= 'a' && str[i] <= 'z' )
						str[i] = str[i] - 32;
					write(1, &str[i], 1);
					write(1, &str[i + 1], 1);
					i++;
				}
				else if (str[i + 1] == '\0')
				{
					if (str[i] >= 'a' && str[i] <= 'z' )
						str[i] = str[i] - 32;
					write(1, &str[i], 1);
					write(1, "\n", 1);
					i++;
				}
			}
			j++;
		}
	}
	else 
		write(1, "\n", 1);
	return (0);
}

// Assignment name  : rstr_capitalizer
// Expected files   : rstr_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or more strings and, for each argument, puts 
// the last character that is a letter of each word in uppercase and the rest
// in lowercase, then displays the result followed by a \n.

// A word is a section of string delimited by spaces/tabs or the start/end of the
// string. If a word has a single letter, it must be capitalized.

// A letter is a character in the set [a-zA-Z]

// If there are no parameters, display \n.

// Examples:

// $> ./rstr_capitalizer | cat -e
// $
// $> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
// A firsT littlE tesT$
// $> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
// seconD tesT A littlE biT   moaR compleX$
//    but... thiS iS noT thaT compleX$
//      okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
// $>

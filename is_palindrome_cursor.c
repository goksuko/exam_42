#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_capital(char c)
{
    return (c >= 'A' && c <= 'Z');
}


bool is_not_letter(char s)
{
    if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
        return false;
    return true;
}

bool is_palindrome(char *str)
{
    if (str == NULL)
        return true;

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        // Skip non-letter characters from left
        while (left < right && is_not_letter(str[left]))
            left++;

        // Skip non-letter characters from right
        while (left < right && is_not_letter(str[right]))
            right--;

        // Convert to lowercase for comparison
        char left_char = str[left];
        char right_char = str[right];

        if (is_capital(left_char))
            left_char += 32;
        if (is_capital(right_char))
            right_char += 32;

        // Compare characters
        if (left_char != right_char)
            return false;

        left++;
        right--;
    }

    return true;
}

int main(void) {
  bool answer;
  char *str;
  
  str = " at au  ";  
  answer = is_palindrome(str);
  
  if (answer == true) 
    printf("It's a palindrome.\n");
  else
    printf("It's not a palindrome.\n");
  return 0;
}
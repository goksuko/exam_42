#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Palindrome: "Was it a car or a cat I saw?????", "noon", "Dad"
// enhanced

bool is_not_letter(char x)
{
  if (x >= 'A' && x <= 'Z')
    return false;
  else if (x >= 'a' && x <= 'z')
    return false;
  else
    return true;
}


bool is_capital(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

bool is_palindrome(char *str)
{
  int i;
  int j;
  int len;
  bool is_first;
  
  i = 0;
  len = strlen(str);
  j = len - 1;
  is_first = true;
  if (str == NULL)
    return true;
  while(j - i >= 2 && str[i] != '\0' && str[j] != '\0')
  {
    while (is_not_letter(str[i]) && str[i] != '\0')
      i++;
    while (is_not_letter(str[j]) && str[j] != '\0')
      j--;
    if (is_capital(str[i]))
      str[i] += 32;
    if (is_capital(str[j]))
      str[j] += 32;
    if (i == len && is_first)
      return true;      
    if (str[i] != str[j])
      return false;
    else
    {
      i++;
      j--;
    }
    is_first = false;
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

// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>

// // Palindrome: "Was it a car or a cat I saw?????", "noon", "Dad"
// // my_solution

// bool is_palindrome(char *str)
// {
//   int i;
//   int j;
//   int len;
//   bool is_first;
  
//   i = 0;
//   len = strlen(str);
//   j = len - 1;
//   is_first = true;
//   if (str == NULL)
//     return true;
//   while(j - i >= 2 && str[i] != '\0' && str[j] != '\0')
//   {
//     while ((str[i] < 'A' || str[i] > 'Z') && str[i] != '\0')
//       i++;
//     while ((str[i] < 'a' || str[i] > 'z') && str[i] != '\0')
//       i++;
//     while ((str[j] < 'A' || str[j] > 'Z') && str[j] != '\0')
//       j--;
//     while ((str[j] < 'a' || str[j] > 'z') && str[j] != '\0')
//       j--;
//     if (str[i] >= 'A' && str[i] <= 'Z')
//       str[i] += 32;
//     if (str[j] >= 'A' && str[j] <= 'Z')
//       str[j] += 32;
//     if (i == len && is_first)
//       return true;      
//     if (str[i] != str[j])
//       return false;
//     else
//     {
//       i++;
//       j--;
//     }
//     is_first = false;
//   }
//   return true;
// }

// int main(void) {
//   bool answer;
//   char *str;
  
//   str = "    ";  
//   answer = is_palindrome(str);
  
//   if (answer == true) 
//     printf("It's a palindrome.\n");
//   else
//     printf("It's not a palindrome.\n");
//   return 0;
// }

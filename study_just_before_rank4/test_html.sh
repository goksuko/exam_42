cc -Wall -Werror -Wextra html_validator.c -o html_validator
./html_validator '<b><blue></blue></b>'; echo $?
echo above should be: 0

./html_validator '<b><blue></b></blue>'; echo $?
echo above should be: 1

./html_validator '<blue attribute="bladiebla"></blue>'; echo $?
echo above should be: 0

./html_validator '<img bladiebla><blue></blue>'; echo $?
echo above should be: 0
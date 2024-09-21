#include <stdio.h>

void sort_in_tab(int *array, int len)
{
    int temp;
    int i;


    i = 0;
    while (i < len - 1)
    {
        if (array[i] > array[i + 1])
        {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = 0;
        }
        else
            i++;
    }
    return ;
}

int main()
{
    int array[9] = {3, 5, 6, 2, 3 ,6, 1, 7, 8};
    int i;

    i = 0;
    while (i < 9)
    {
        printf("%d, ", array[i]);
        i++;
    }
    printf("\nsorted:\n");
    sort_in_tab(array, 9);
    i = 0;
    while (i < 9)
    {
        printf("%d, ", array[i]);
        i++;
    }
    return(0);
}

#include <stdio.h>
#include "console_utils.h"

int main()
{
    char str[100], i = 0, length;
    printf("\n Enter the string : ");
    fgets(str, 100, stdin);
    while (str[i] != '\0')
        i++;
    length = i;
    printf("\n The length of the string is : %d", length);
    getch();
    return 0;
}

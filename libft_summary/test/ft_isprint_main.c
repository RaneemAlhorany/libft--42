#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
    char tests[] = {'A', ' ', '~', '\n', '\t'};
    int i = 0;

    printf("=== ft_isprint vs isprint ===\n\n");

    while (i < 5)
    {
        printf("Input: ASCII %d\n", tests[i]);
        printf("ft_isprint: %d\n", ft_isprint(tests[i]));
        printf("isprint   : %d\n", isprint(tests[i]));
        printf("----------------------\n");
        i++;
    }
    return (0);
}

/*
Expected Output Notes:
- Printable chars → true
- '\n','\t' → false
*/
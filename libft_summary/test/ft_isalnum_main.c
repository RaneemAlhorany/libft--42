#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
    char tests[] = {'A', 'z', '5', '#', ' '};
    int i = 0;

    printf("=== ft_isalnum vs isalnum ===\n\n");

    while (i < 5)
    {
        printf("Input: '%c'\n", tests[i]);
        printf("ft_isalnum: %d\n", ft_isalnum(tests[i]));
        printf("isalnum   : %d\n", isalnum(tests[i]));
        printf("----------------------\n");
        i++;
    }
    return (0);
}

/*
Expected Output Notes:
- 'A','z','5' → non-zero
- '#',' ' → 0
*/
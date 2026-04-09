#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
    char tests[] = {'0', '5', '9', 'a', ' '};
    int i = 0;

    printf("=== ft_isdigit vs isdigit ===\n\n");

    while (i < 5)
    {
        printf("Input: '%c'\n", tests[i]);
        printf("ft_isdigit: %d\n", ft_isdigit(tests[i]));
        printf("isdigit   : %d\n", isdigit(tests[i]));
        printf("----------------------\n");
        i++;
    }
    return (0);
}

/*
Expected Output Notes:
- '0'–'9' → true
- others → 0
*/
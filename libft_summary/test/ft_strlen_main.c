#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char *tests[] = {"Hello", "", "42AbuDhabi", NULL};
    int i = 0;

    printf("=== ft_strlen vs strlen ===\n\n");

    while (tests[i])
    {
        printf("Input: \"%s\"\n", tests[i]);
        printf("ft_strlen: %zu\n", ft_strlen(tests[i]));
        printf("strlen   : %zu\n", strlen(tests[i]));
        printf("----------------------\n");
        i++;
    }

    return (0);
}

/*
Expected Output Notes:
- "Hello" → 5
- "" → 0
- "42AbuDhabi" → 11
- NULL → (undefined behavior, should NOT be tested)
*/
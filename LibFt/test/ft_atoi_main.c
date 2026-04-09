#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *tests[] = {"42", "   -42", "1337abc", "abc123", NULL};
    int i = 0;

    printf("=== ft_atoi vs atoi ===\n\n");

    while (tests[i])
    {
        printf("Input: \"%s\"\n", tests[i]);
        printf("ft_atoi: %d\n", ft_atoi(tests[i]));
        printf("atoi   : %d\n", atoi(tests[i]));
        printf("----------------------\n");
        i++;
    }

    return (0);
}

/*
Expected Output Notes:
- "42" → 42
- "   -42" → -42
- "1337abc" → 1337
- "abc123" → 0
*/
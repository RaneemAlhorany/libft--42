#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
    int tests[] = {0, 65, 127, 128, 200};
    int i = 0;

    printf("=== ft_isascii vs isascii ===\n\n");

    while (i < 5)
    {
        printf("Input: %d\n", tests[i]);
        printf("ft_isascii: %d\n", ft_isascii(tests[i]));
        printf("isascii   : %d\n", isascii(tests[i]));
        printf("----------------------\n");
        i++;
    }
    return (0);
}

/*
Expected Output Notes:
- 0–127 → true
- >127 → false
*/
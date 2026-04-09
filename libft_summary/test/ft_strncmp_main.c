#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    printf("=== ft_strncmp vs strncmp ===\n\n");

    printf("Compare \"abc\" vs \"abd\" (3)\n");
    printf("ft_strncmp: %d\n", ft_strncmp("abc", "abd", 3));
    printf("strncmp   : %d\n", strncmp("abc", "abd", 3));

    printf("\nCompare \"abc\" vs \"abc\" (3)\n");
    printf("ft_strncmp: %d\n", ft_strncmp("abc", "abc", 3));
    printf("strncmp   : %d\n", strncmp("abc", "abc", 3));

    return (0);
}

/*
Expected Output Notes:
- "abc" vs "abd" → negative value
- "abc" vs "abc" → 0
*/

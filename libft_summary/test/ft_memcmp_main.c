#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    printf("=== ft_memcmp vs memcmp ===\n\n");

    printf("Compare \"abc\" vs \"abd\"\n");
    printf("ft_memcmp: %d\n", ft_memcmp("abc", "abd", 3));
    printf("memcmp   : %d\n", memcmp("abc", "abd", 3));

    printf("\nCompare \"abc\" vs \"abc\"\n");
    printf("ft_memcmp: %d\n", ft_memcmp("abc", "abc", 3));
    printf("memcmp   : %d\n", memcmp("abc", "abc", 3));

    return (0);
}

/*
Expected Output Notes:
- "abc" vs "abd" → negative
- identical → 0
*/
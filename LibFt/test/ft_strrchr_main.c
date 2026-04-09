#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char *str = "hello";

    printf("=== ft_strrchr vs strrchr ===\n\n");

    printf("Search 'l'\n");
    printf("ft_strrchr: %s\n", ft_strrchr(str, 'l'));
    printf("strrchr   : %s\n", strrchr(str, 'l'));

    printf("\nSearch 'x'\n");
    printf("ft_strrchr: %p\n", ft_strrchr(str, 'x'));
    printf("strrchr   : %p\n", strrchr(str, 'x'));

    return (0);
}

/*
Expected Output Notes:
- 'l' → returns "lo" (last occurrence)
- 'x' → returns NULL
*/
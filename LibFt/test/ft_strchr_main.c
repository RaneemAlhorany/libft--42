#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char *str = "hello";

    printf("=== ft_strchr vs strchr ===\n\n");

    printf("Search 'l'\n");
    printf("ft_strchr: %s\n", ft_strchr(str, 'l'));
    printf("strchr   : %s\n", strchr(str, 'l'));

    printf("\nSearch 'x'\n");
    printf("ft_strchr: %p\n", ft_strchr(str, 'x'));
    printf("strchr   : %p\n", strchr(str, 'x'));

    return (0);
}

/*
Expected Output Notes:
- 'l' → returns "llo"
- 'x' → returns NULL
*/
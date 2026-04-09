#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char str[] = "hello world";

    printf("=== ft_memchr vs memchr ===\n\n");

    printf("Search 'o'\n");
    printf("ft_memchr: %s\n", (char *)ft_memchr(str, 'o', 11));
    printf("memchr   : %s\n", (char *)memchr(str, 'o', 11));

    printf("\nSearch 'x'\n");
    printf("ft_memchr: %p\n", ft_memchr(str, 'x', 11));
    printf("memchr   : %p\n", memchr(str, 'x', 11));

    return (0);
}

/*
Expected Output Notes:
- 'o' → "o world"
- 'x' → NULL
*/
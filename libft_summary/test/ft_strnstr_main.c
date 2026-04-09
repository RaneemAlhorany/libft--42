#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    printf("=== ft_strnstr vs strnstr ===\n\n");

    printf("Search \"world\" in \"hello world\"\n");
    printf("ft_strnstr: %s\n", ft_strnstr("hello world", "world", 11));
    printf("strnstr   : %s\n", strnstr("hello world", "world", 11));

    printf("\nSearch \"abc\"\n");
    printf("ft_strnstr: %p\n", ft_strnstr("hello", "abc", 5));
    printf("strnstr   : %p\n", strnstr("hello", "abc", 5));

    return (0);
}

/*
Expected Output Notes:
- found → "world"
- not found → NULL
*/
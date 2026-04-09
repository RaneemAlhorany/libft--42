#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
    printf("=== ft_tolower vs tolower ===\n\n");

    printf("Input 'A'\n");
    printf("ft: %c\n", ft_tolower('A'));
    printf("libc: %c\n", tolower('A'));

    printf("\nInput 'a'\n");
    printf("ft: %c\n", ft_tolower('a'));
    printf("libc: %c\n", tolower('a'));

    return (0);
}

/*
Expected Output Notes:
- 'A' → 'a'
- 'a' → unchanged
*/
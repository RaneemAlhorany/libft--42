#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
    printf("=== ft_toupper vs toupper ===\n\n");

    printf("Input 'a'\n");
    printf("ft: %c\n", ft_toupper('a'));
    printf("libc: %c\n", toupper('a'));

    printf("\nInput 'A'\n");
    printf("ft: %c\n", ft_toupper('A'));
    printf("libc: %c\n", toupper('A'));

    return (0);
}

/*
Expected Output Notes:
- 'a' → 'A'
- 'A' → unchanged
*/
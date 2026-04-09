#include <stdio.h>
#include <strings.h>
#include "libft.h"

int main(void)
{
    char str1[10] = "abcdef";
    char str2[10] = "abcdef";

    printf("=== ft_bzero vs bzero ===\n\n");

    ft_bzero(str1, 3);
    bzero(str2, 3);

    printf("ft_bzero: %s\n", str1);
    printf("bzero   : %s\n", str2);

    return (0);
}

/*
Expected Output Notes:
- First 3 bytes become '\0'
- Printing string may look empty or truncated
*/
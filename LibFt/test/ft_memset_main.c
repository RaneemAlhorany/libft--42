#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char str1[10] = "abcdef";
    char str2[10] = "abcdef";

    printf("=== ft_memset vs memset ===\n\n");

    ft_memset(str1, 'X', 3);
    memset(str2, 'X', 3);

    printf("ft_memset: %s\n", str1);
    printf("memset   : %s\n", str2);

    return (0);
}

/*
Expected Output Notes:
- "XXXdef"
*/
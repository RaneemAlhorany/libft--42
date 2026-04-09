#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char str1[] = "123456";
    char str2[] = "123456";

    printf("=== ft_memmove vs memmove ===\n\n");

    ft_memmove(str1 + 2, str1, 4);
    memmove(str2 + 2, str2, 4);

    printf("ft_memmove: %s\n", str1);
    printf("memmove   : %s\n", str2);

    return (0);
}

/*
Expected Output Notes:
- Both should output: "121234"
- memmove handles overlap correctly
*/
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char src[] = "Hello World";
    char dst1[20];
    char dst2[20];

    printf("=== ft_memcpy vs memcpy ===\n\n");

    ft_memcpy(dst1, src, 12);
    memcpy(dst2, src, 12);

    printf("ft_memcpy: %s\n", dst1);
    printf("memcpy   : %s\n", dst2);

    return (0);
}

/*
Expected Output Notes:
- Both outputs should be identical: "Hello World"
- memcpy is NOT safe for overlapping memory
*/
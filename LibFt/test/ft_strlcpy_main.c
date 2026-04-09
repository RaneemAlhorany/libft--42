#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char dst1[10];
    char dst2[10];
    char *src = "HelloWorld";

    printf("=== ft_strlcpy vs strlcpy ===\n\n");

    printf("ft_strlcpy: %zu\n", ft_strlcpy(dst1, src, 10));
    printf("strlcpy   : %zu\n", strlcpy(dst2, src, 10));

    printf("ft result: %s\n", dst1);
    printf("libc res : %s\n", dst2);

    return (0);
}

/*
Expected Output Notes:
- Copies up to size-1 chars
- Always null-terminated
- Return = length of src
*/
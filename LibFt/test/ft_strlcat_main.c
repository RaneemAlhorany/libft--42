#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char dst1[20] = "Hello ";
    char dst2[20] = "Hello ";
    char *src = "World";

    printf("=== ft_strlcat vs strlcat ===\n\n");

    printf("ft_strlcat: %zu\n", ft_strlcat(dst1, src, 20));
    printf("strlcat   : %zu\n", strlcat(dst2, src, 20));

    printf("ft result: %s\n", dst1);
    printf("libc res : %s\n", dst2);

    return (0);
}

/*
Expected Output Notes:
- Result string: "Hello World"
- Return value = total length tried to create
*/
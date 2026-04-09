#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *res = ft_substr("hello world", 6, 5);

    printf("=== ft_substr ===\n\n");
    printf("Result: %s\n", res);

    free(res);
    return (0);
}

/*
Expected Output Notes:
- "world"
*/
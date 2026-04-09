#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *res = ft_strjoin("hello ", "world");

    printf("=== ft_strjoin ===\n\n");
    printf("Result: %s\n", res);

    free(res);
    return (0);
}

/*
Expected Output Notes:
- "hello world"
*/

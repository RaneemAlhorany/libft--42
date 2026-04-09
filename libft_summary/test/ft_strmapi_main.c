#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char my_func(unsigned int i, char c)
{
    return c + i;
}

int main(void)
{
    char *res = ft_strmapi("abc", my_func);

    printf("=== ft_strmapi ===\n\n");
    printf("Result: %s\n", res);

    free(res);
    return (0);
}

/*
Expected Output Notes:
- "ace"
*/
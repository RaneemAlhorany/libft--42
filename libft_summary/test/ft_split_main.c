#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char **res = ft_split("a,b,c", ',');

    printf("=== ft_split ===\n\n");

    for (int i = 0; res[i]; i++)
        printf("res[%d]: %s\n", i, res[i]);

    for (int i = 0; res[i]; i++)
        free(res[i]);
    free(res);

    return (0);
}

/*
Expected Output Notes:
- "a"
- "b"
- "c"
*/
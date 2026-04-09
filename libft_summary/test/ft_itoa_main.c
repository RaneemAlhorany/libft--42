#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *res = ft_itoa(-12345);

    printf("=== ft_itoa ===\n\n");
    printf("Result: %s\n", res);

    free(res);
    return (0);
}

/*
Expected Output Notes:
- "-12345"
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *s1 = ft_strdup("hello");
    char *s2 = strdup("hello");

    printf("=== ft_strdup vs strdup ===\n\n");

    printf("ft_strdup: %s\n", s1);
    printf("strdup   : %s\n", s2);

    free(s1);
    free(s2);

    return (0);
}

/*
Expected Output Notes:
- Both should print "hello"
- Memory must be independently allocated
*/
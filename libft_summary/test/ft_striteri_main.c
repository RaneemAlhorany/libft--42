#include <stdio.h>
#include "libft.h"

void my_func(unsigned int i, char *c)
{
    *c += i;
}

int main(void)
{
    char str[] = "abc";

    printf("=== ft_striteri ===\n\n");

    ft_striteri(str, my_func);
    printf("Result: %s\n", str);

    return (0);
}

/*
Expected Output Notes:
- "ace"
*/
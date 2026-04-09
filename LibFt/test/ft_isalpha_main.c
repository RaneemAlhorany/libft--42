#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
    char tests[] = {'A', 'z', '5', ' ', '\n'};
    int i = 0;

    printf("=== ft_isalpha vs isalpha ===\n\n");

    while (i < 5)
    {
        printf("Input: '%c'\n", tests[i]);
        printf("ft_isalpha: %d\n", ft_isalpha(tests[i]));
        printf("isalpha   : %d\n", isalpha(tests[i]));
        printf("----------------------\n");
        i++;
    }

    return (0);
}

/*
Expected Output Notes:
- 'A' → both return non-zero (true)
- 'z' → both return non-zero (true)
- '5' → both return 0
- ' ' → both return 0
- '\n' → both return 0
*/
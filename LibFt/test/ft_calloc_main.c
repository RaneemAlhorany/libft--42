#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    int *arr1 = ft_calloc(5, sizeof(int));
    int *arr2 = calloc(5, sizeof(int));

    printf("=== ft_calloc vs calloc ===\n\n");

    for (int i = 0; i < 5; i++)
        printf("ft: %d | libc: %d\n", arr1[i], arr2[i]);

    free(arr1);
    free(arr2);

    return (0);
}

/*
Expected Output Notes:
- All values should be 0
*/
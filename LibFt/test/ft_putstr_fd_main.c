#include <unistd.h>
#include "libft.h"

int main(void)
{
    write(1, "=== ft_putstr_fd ===\n\n", 23);

    ft_putstr_fd("Hello World", 1);
    write(1, "\n", 1);

    return (0);
}

/*
Expected Output Notes:
- Prints: Hello World
*/
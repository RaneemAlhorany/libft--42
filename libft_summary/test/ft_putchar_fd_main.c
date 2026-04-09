#include <unistd.h>
#include "libft.h"

int main(void)
{
    write(1, "=== ft_putchar_fd ===\n\n", 24);

    ft_putchar_fd('A', 1);
    write(1, "\n", 1);

    return (0);
}

/*
Expected Output Notes:
- Prints: A
- Output goes to file descriptor (1 = stdout)
*/

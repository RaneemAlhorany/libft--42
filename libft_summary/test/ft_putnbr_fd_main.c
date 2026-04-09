#include <unistd.h>
#include "libft.h"

int main(void)
{
    write(1, "=== ft_putnbr_fd ===\n\n", 23);

    ft_putnbr_fd(42, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-12345, 1);
    write(1, "\n", 1);

    return (0);
}

/*
Expected Output Notes:
- 42
- -12345
*/